let app = angular.module("app",[]), toggle = false;
let btnClose = document.querySelector(".btnClose"), btnToggleVideo = document.querySelector(".btnToggleVideo");
let messageprompt = document.querySelector(".messageprompt"), yesprompt = document.querySelector(".yesprompt");
let noprompt = document.querySelector(".noprompt"), camera = document.querySelector(".camera");

app.run($rootScope => {
    $rootScope.levels = ["1","2","3","4"];
    $rootScope.courses = ["BSIT","BSCS","BSCPE","BSAMT"]
})

app.controller("userList",($scope,$http) => {
    $scope.header=["id","username","password","edit | delete"];
    $http.get("/user").then(response => {
        $scope.users=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = id => $http.delete(`/user/${id}`).then(() => location.reload())
})

app.controller("studentList",($scope,$http) => {
    $scope.header=["idno","Image Profile","lastname","firstname","course","level","edit | delete"];
    $http.get("/student").then(response => {
        $scope.students=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = idno => $http.delete(`/student/${idno}`).then(() => location.reload())
})

app.controller("updateUser",($scope,$http) => {
    $scope.updateUser = () => {
        $http.put("/user", {
            id: $scope.id,
            username: $scope.username,
            password: $scope.password
        }).then(() => location.reload())
    }
})

app.controller("updateStudent",($scope,$http,$rootScope) => {
    $scope.courses = $rootScope.courses;
    $scope.levels = $rootScope.levels;
    $scope.updateStudent = () => {
        $http.put("/student",{
            idno: $scope.idno,
            lastname: $scope.lastname,
            firstname: $scope.firstname,
            course: $scope.selectedCourse,
            level: $scope.selectedLevel
        }).then(() => location.reload())
    }
})

const show = element => element.style.display = "block";
const hide = element => element.style.display = "none";

hide(messageprompt)
hide(yesprompt)
hide(noprompt)

Webcam.set({
    width: 500,
    height: 480,
    dest_width: 1080,
    dest_height: 720,
    image_format: 'jpeg',
    jpeg_quality: 100
});

btnToggleVideo.addEventListener("click", () => {
    if(btnToggleVideo.children[0].classList.contains("bi-camera-video-off-fill")){
        btnToggleVideo.children[0].setAttribute("class","bi bi-camera-video-fill")
        Webcam.attach('.camera')
        show(camera)
    } else {
        btnToggleVideo.children[0].setAttribute("class","bi bi-camera-video-off-fill")
        Webcam.reset('.camera');
        hide(messageprompt)
        hide(yesprompt)
        hide(noprompt)
        hide(camera)
    }
})
btnClose.addEventListener("click", () => Webcam.reset('.camera'))
document.querySelector(".btnSnapshot").addEventListener("click", () => {
    Webcam.freeze();
    show(messageprompt)
    show(yesprompt)
    show(noprompt)
})
yesprompt.addEventListener("click", () => {
    hide(messageprompt)
    hide(yesprompt)
    hide(noprompt)
    Webcam.snap(data_uri => download(data_uri))
})
noprompt.addEventListener("click", () => {
    hide(messageprompt)
    hide(yesprompt)
    hide(noprompt)
    Webcam.unfreeze();
})