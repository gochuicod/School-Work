const express = require("express"), mysql = require("mysql"), bodyparser = require("body-parser"), path = require("path");

let port = process.env.port || 8000, app = express()
let config = {
    host: "localhost",
    user: "root",
    password: "",
    database: "Sysint",
    charset: "utf8mb4",
    multipleStatement: true
}
let db = mysql.createPool(config)

let server = app.listen(port, () => require("dns").lookup(require("os").hostname(), (err,addr,fam) => console.log(`http://${addr}:${port}`)))

app.use(express.static('./public',{index:'login.html'}))
app.use(bodyparser.urlencoded({"extended":true}))
app.use(bodyparser.json())

app.get("/homepage",(req,res) => res.sendFile(`${__dirname}/public/index.html`))

app.post("/user",(req,res) => {
    let users = req.body;
    let sql = `insert into tbluser (username,password) values ('${users.username}','${users.password}')`;
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"New user added!"}))
})

app.get("/user",(req,res) => {
    let sql = "select * from tbluser"
    db.query(sql, (err,results) => err ? res.status(500).json(err) : res.json(results))
})

app.put("/user",(req,res) => {
    let users = req.body;
    let sql = `update tbluser set username='${users.username}', password='${users.password}' where id=${users.id}`;
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"User updated!"}));
})

app.delete("/user/:id",(req,res) => {
    let sql = `delete from tbluser where id=${req.params.id}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"User removed!"}));
    // db.query('alter table tbluser auto_increment=1')
})

app.post("/student",(req,res) => {
    let students = req.body;
    let sql = `insert into tblstudent (lastname,firstname,course,level) values ('${students.lastname}','${students.firstname}','${students.course}','${students.level}')`;
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"New studend added!"}))
})

app.get("/student",(req,res) => {
    let sql = "select * from tblstudent"
    db.query(sql, (err,results) => err ?  res.status(500).json(err) : res.json(results))
})

app.put("/student",(req,res) => {
    let students = req.body;
    let sql = `update tblstudent set lastname='${students.lastname}', firstname='${students.firstname}', course='${students.course}', level='${students.level}' where idno=${students.idno}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"Student updated!"}))
})

app.delete("/student/:id",(req,res) => {
    let sql = `delete from tblstudent where idno=${req.params.id}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"Student removed!"}))
    // db.query('alter table tblstudent auto_increment=1')
})