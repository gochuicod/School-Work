let app = angular.module("app",[]);

app.run($rootScope => {
    $rootScope.levels = ["1","2","3","4"];
    $rootScope.courses = ["BSIT","BSCS","BSCPE","BSAMT"]
    $rootScope.studentIdNo = 0;
    $rootScope.studentImgPath = '';
    $rootScope.userId = 0;
    $rootScope.username = '';
    $rootScope.password = '';
})

app.controller("userList",($scope,$http,$rootScope) => {
    $scope.header=["username","password","edit | delete"];
    $http.get("/user").then(response => {
        $scope.users=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = id => $http.delete(`/user/${id}`).then(() => location.reload())
    $scope.updateUser = (id,username,password) => {
        $rootScope.userId = id;
        $rootScope.username = username;
        $rootScope.password = password;
    }
})

app.controller("studentList",($scope,$http,$rootScope) => {
    $scope.header=["lastname","firstname","course","level","edit | delete"];
    $http.get("/student").then(response => {
        $scope.students=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = idno => $http.delete(`/student/${idno}`).then(() => location.reload())
    $scope.updateStudent = (idno,imagepath) => {
        $rootScope.studentIdNo = idno;
        $rootScope.studentImgPath = imagepath;
    }
})

app.controller("updateUser",($scope,$http,$rootScope) => {
    $scope.updateUser = () => {
        $http.put("/user/update", {
            id: $rootScope.userId,
            username: $scope.username,
            password: $scope.password
        }).then(() => location.reload())
    }
})

app.controller("updateStudent",($scope,$http,$rootScope) => {
    $scope.courses = $rootScope.courses;
    $scope.levels = $rootScope.levels;
    $rootScope.$watch('studentImgPath',() => {
        $scope.image = $rootScope.studentImgPath;
    })
    $scope.updateStudent = () => {
        $http.put("/student/update",{
            idno: $rootScope.studentIdNo,
            lastname: $scope.lastname,
            firstname: $scope.firstname,
            course: $scope.selectedCourse,
            level: $scope.selectedLevel
        }).then(() => location.reload())
    }
})

let lastname = document.querySelector(".lastname"), firstname = document.querySelector(".firstname");
let course = document.querySelector(".course"), level = document.querySelector(".level");
let video = document.querySelector(".video");

Webcam.set({
    width: 550,
    height: 310,
    dest_width: 1080,
    dest_height: 720,
    image_format: 'jpeg',
    jpeg_quality: 100,
    flip_horiz: true,
})

document.querySelector(".capture").addEventListener("click", () => Webcam.freeze())
document.querySelector(".reset").addEventListener("click", () => Webcam.unfreeze())
document.querySelector(".upload").addEventListener("click", () => {
    if(lastname.value != "" || firstname.value != ""){
        Webcam.snap(data_uri => {
            Webcam.upload(data_uri,`/student?lastname=${lastname.value}&firstname=${firstname.value}&course=${course.value}&level=${level.value}`,(code,image) => {
                alert("New Student Added!")
                location.reload();
            })
        })
    } else alert('Fill in the empty fields!')
})

video.addEventListener("click", () => {
    if(video.firstChild.classList.contains("bi-camera-video-off-fill")){
        video.setAttribute("class","video btn btn-dark")
        video.firstChild.setAttribute("class","bi bi-camera-video-fill")
        Webcam.attach('.camera')
    } else {
        video.setAttribute("class","video btn btn-danger")
        video.firstChild.setAttribute("class","bi bi-camera-video-off-fill")
        Webcam.reset('.camera')
    }
})