const express = require("express"), mysql = require("mysql"), bodyparser = require("body-parser"), path = require("path");

let port = process.env.port || 8000, app = express()

app.use(express.static('./public',{index:'login.html'}))
app.use(bodyparser.urlencoded({"extended":true}))
app.use(bodyparser.json())

let config = {
    host: "localhost",
    user: "root",
    password: "",
    database: "user_management",
    charset: "utf8mb4",
    multipleStatement: true
}

let db = mysql.createPool(config)

app.get("/",(req,res) => res.sendFile(`${__dirname}/public/login.html`))

app.get("/main",(req,res) => res.sendFile(`${__dirname}/public/index.html`))

app.get("/users",(req,res) => {
    let sql = "select * from tblusers"
    db.query(sql, (err,results,fields) => err ? res.status(500).json(err) : res.json(results))
})

app.post("/users",(req,res) => {
    let users = req.body;
    let sql = `insert into tblusers (username,password) values ('${users.username}','${users.password}')`;
    db.query(sql, (err,results,fields) => err ? res.status(500).json(err) : res.json({"message":"New user added!"}))
})

app.delete("/users/:userID",(req,res) => {
    let userID = req.params.userID;
    let sql = `delete from tblusers where =${userID}`
    db.query(sql, (err,results,fields) => err ? res.status(500).json(err) : res.json({"message":"User removed!"}));
})

app.put("/users",(req,res) => {
    let users = req.body;
    let sql = `update tblusers set username='${users.username}', password='${users.password}' where userID=${users.userID}`;
    db.query(sql, (err,results,fields) => err ? res.status(500).json(err) : res.json({"message":"User updated!"}));
})

let server = app.listen(port, () => {
    require("dns").lookup(require("os").hostname(), (err,addr,fam) => console.log(`http://${addr}:${port}`))
})