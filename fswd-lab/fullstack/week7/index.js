const express=require("express")
const app=express()
const path=require("path")
const hbs=require("hbs")
const collection=require("./mong")
const templatePath=path.join(__dirname,'../templates')
app.use(express.json())
app.set("view engine","hbs")
app.set("views",templatePath)
app.use(express.urlencoded({extended:false}))

app.get("/", (req,res)=>{
    res.render("login")
})
app.post("/login",async(req,res)=>{
    try{
    const check=await collection.findOne({name:req.body.name})
        if(check.password===req.body.password)
        {
            res.render("home")
        }
        else{
            res.send("wrong")
        }
    }
    catch
    {
        res.send("Wrong Details")
    }
}) 
app.listen(3002, ()=>{
    console.log("Port Connected")
})
