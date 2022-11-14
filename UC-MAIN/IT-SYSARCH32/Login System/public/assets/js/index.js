let app = angular.module("app",[]);

app.run($rootScope => {
    $rootScope.levels = ["1","2","3","4"];
    $rootScope.courses = ["BSIT","BSCS","BSCPE","BSAMT"]
})

app.controller("userList",($scope,$http) => {
    $scope.header=["id","username","password"];
    $http({
        method:"GET",
        url:"/user"
    }).then(response => {
        $scope.users=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = id => {
        $http({
            method:"DELETE",
            url:`/user/${id}`
        }).then(() => {
            $http({
                method:"GET",
                url:"/user"
            }).then(response => $scope.users=response.data)
        })
    }
})

app.controller("studentList",($scope,$http) => {
    $scope.header=["idno","lastname","firstname","course","level"];
    $http({
        method:"GET",
        url:"/student"
    }).then(response => {
        $scope.students=response.data;
        if(response.data.length === 0) $scope.setDisplay = {"display":"none"}
        else $scope.setDisplay = {"display":"block"}
    });
    $scope.remove = idno => {
        $http({
            method:"DELETE",
            url:`/student/${idno}`
        }).then(() => {
            $http({
                method:"GET",
                url:"/student"
            }).then(response => $scope.students=response.data)
        })
    }
})

app.controller("registerUser",($scope,$http) => {
    $scope.registerUser = () => {
        $http({
            method:"POST",
            url:"/user",
            headers: {
                'Content-Type': 'application/json'
            },
            data: {
                username: $scope.username,
                password: $scope.password
            }
        }).then(() => location.reload())
    }
})

app.controller("registerStudent",($scope,$http,$rootScope) => {
    $scope.courses = $rootScope.courses;
    $scope.levels = $rootScope.levels;
    $scope.registerStudent = () => {
        $http({
            method:"POST",
            url:"/student",
            headers: {
                'Content-Type': 'application/json'
            },
            data: {
                lastname: $scope.lastname,
                firstname: $scope.firstname,
                course: $scope.selectedCourse,
                level: $scope.selectedLevel
            }
        }).then(() => location.reload())
    }
})

app.controller("updateUser",($scope,$http) => {
    $scope.updateUser = () => {
        $http({
            method:"PUT",
            url:"/user",
            headers: {
                'Content-Type': 'application/json'
            },
            data: {
                id: $scope.id,
                username: $scope.username,
                password: $scope.password
            }
        }).then(() => location.reload())
    }
})

app.controller("updateStudent",($scope,$http,$rootScope) => {
    $scope.courses = $rootScope.courses;
    $scope.levels = $rootScope.levels;
    $scope.updateStudent = () => {
        $http({
            method:"PUT",
            url:"/student",
            headers: {
                'Content-Type': 'application/json'
            },
            data: {
                idno: $scope.idno,
                lastname: $scope.lastname,
                firstname: $scope.firstname,
                course: $scope.selectedCourse,
                level: $scope.selectedLevel
            }
        }).then(() => location.reload())
    }
})

app.controller("loginLogoutController",($scope,$http) => {
    $scope.login = () => {
        $http({
            method:"GET",
            url:"/user"
        }).then(response => {
            let data = response.data;
            let matchCredentials = data.some(element => $scope.username == element.username && $scope.password == element.password)
            
            if($scope.username == "admin" && $scope.password == "user") window.location.href = "/homepage";
            else if (matchCredentials) window.location.href = "/homepage"
            else {
                alert("Incorrect username and/or password!")
                $scope.username = ''; $scope.password = '';
            }
        })
    }
    $scope.logout = () => window.location.href = "http://localhost:8000"
})