let app = angular.module("app",[]);

app.controller("index",($scope,$http) => {
    $scope.header=["username","password"];
    $http({
        method:"GET",
        url:"http://localhost:8000/user"
    }).then(response => {
        $scope.users=response.data
    });
})

app.controller("register",($scope,$http) => {
    $scope.register = () => {
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

let login = {
    username: document.querySelector(".username"),
    password: document.querySelector(".password"),
    api: "http://localhost:8000/user",
    compare: async function(){
        const sample = await fetch(this.api)
        const data = await sample.json()
        if(this.username.value == "admin" && this.password.value == "user") window.location.href = "http://localhost:8000/homepage"
        data.forEach(item => { if(this.username.value == item.username && this.password.value == item.password) window.location.href = "http://localhost:8000/homepage" })
    }
}

let logout = () => window.location.href = "http://localhost:8000"