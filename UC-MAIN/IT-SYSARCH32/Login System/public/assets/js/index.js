(() => {
    let app = angular.module("app",[]);

    app.controller("index",($scope,$http) => {
        $scope.header=["username","password"];
        $http({
            method:"GET",
            url:"http://localhost:8000/users"
        }).then(response => {
            $scope.users=response.data
        });
    })

    app.controller("register",($scope,$http) => {
        $scope.register = () => {
            $http({
                method:"POST",
                url:"/users",
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
})()

let logout = () => window.location.href = "http://localhost:8000"