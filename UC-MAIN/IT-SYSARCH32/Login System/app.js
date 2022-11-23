const express = require('express'), mysql = require('mysql'), bodyparser = require('body-parser'), multer = require('multer');

let port = process.env.port || 8000, app = express()

// This section handles database connection
let config = {
    host: "localhost",
    user: "root",
    password: "",
    database: "Sysint",
    charset: "utf8mb4",
    multipleStatement: true
}
let db = mysql.createPool(config)

// This section handles file data
const fileStorageEngine = multer.diskStorage({
    destination: (req,file,cb) => {
        cb(null,'./public/assets/images')
    },
    filename: (req,file,cb) => {
        cb(null, `${Date.now()}--${file.originalname}`)
    }
})
const upload = multer({storage:fileStorageEngine })

app.listen(port, () => require("dns").lookup(require("os").hostname(), (err,addr,fam) => console.log(`http://${addr}:${port}`)))

app.use(express.static(`${__dirname}/public`))
app.use(bodyparser.urlencoded({"extended":true}))
app.use(bodyparser.json())

app.get("/",(req,res) => res.render("index.html"))

app.get("/main",(req,res) => res.sendFile(`${__dirname}/public/main.html`))

app.post("/user",(req,res) => {
    let { username, password } = req.body;
    let sql = `insert into tbluser (username,password) values ('${username}','${password}')`;
    db.query(sql, err => err ? res.status(500).json(err) : res.redirect("/main"))
})

app.get("/user",(req,res) => {
    let sql = "select * from tbluser"
    db.query(sql, (err,results) => err ? res.status(500).json(err) : res.json(results))
})

app.put("/user",(req,res) => {
    let { username, password, id } = req.body;
    let sql = `update tbluser set username='${username}', password='${password}' where id=${id}`;
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"User updated!"}));
})

app.delete("/user/:id",(req,res) => {
    let sql = `delete from tbluser where id=${req.params.id}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"User removed!"}));
    db.query('alter table tbluser auto_increment=1')
})

app.post("/student",upload.single('image'),(req,res) => {
    let { lastname, firstname, course, level } = req.body, { path } = req.file;
    let sql = `insert into tblstudent (lastname,firstname,course,level,imagepath) values ('${lastname}','${firstname}','${course}','${level}','${path.slice(7,path.length)}')`;
    db.query(sql, err => err ? res.status(500).json(err) : res.redirect("/main"))
})

app.get("/student",(req,res) => {
    let sql = "select * from tblstudent"
    db.query(sql, (err,results) => err ?  res.status(500).json(err) : res.json(results))
})

app.put("/student",(req,res) => {
    let { lastname, firstname, course, level } = req.body;
    let sql = `update tblstudent set lastname='${lastname}', firstname='${firstname}', course='${course}', level='${level}' where idno=${idno}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"Student updated!"}))
})

app.delete("/student/:id",(req,res) => {
    let sql = `delete from tblstudent where idno=${req.params.id}`
    db.query(sql, err => err ? res.status(500).json(err) : res.json({"message":"Student removed!"}))
    db.query('alter table tblstudent auto_increment=1')
})

app.post("/login",(req,res) => {
    let { username, password } = req.body;
    let sql = `select * from tbluser where username='${username}' and password='${password}'`;
    if(username == "admin" && password == "user") res.redirect("/main")
    else{
        db.query(sql,(err,results) => {
            if(err) return res.status(500).json("Login Failed")
            else {
                if(results.length > 0) res.redirect("/main")
                else res.redirect("/?message=LOGIN FAILED")
            }
        })
    }
})