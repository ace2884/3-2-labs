# week-1

## index.html

```html
<!DOCTYPE html>
<html>
<head>
    <title>my personal website</title>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>Page Title</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <link rel='stylesheet' type='text/css' media='screen' href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css">
    <link rel='stylesheet' type='text/css' media='screen' href="main.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body>
    <div class="jumotron text-center">
        <h1 style="font-family:courier;" class="its1">Cmrit</h1>
        <p>think big think placement</p>
    </div>
    <div class="container mt-5">
        <div class="row">
            <div class="col-sm-4">
            <h2 style="font-family:Verdana, Geneva, Tahoma, sans-serif;" class="it">CSD</h2>
            <p>A paragraph is a series of sentences that are organized and coherent, and are all related to a single topic. Almost every piece of writing you do that is longer than a few sentences should be organized into paragraphs. </p>
        </div>  

           <div class="col-sm-4">
            <h2 style="font-family:Verdana, Geneva, Tahoma, sans-serif;" class="it">CSM</h2>
            <p>This is because paragraphs show a reader where the subdivisions of an essay begin and end, and thus help the reader see the organization of the essay and grasp its main points</p>
        </div>
             <div class="col-sm-4">
            <h2 style=" font-family:Verdana, Geneva, Tahoma, sans-serif ;" class="it">CSE</h2>
            <p>Data science is the domain of study that deals with vast volumes of data using modern tools and techniques to find unseen patterns, derive meaningful information, and make business decisions. Data science uses complex machine learning algorithms to build predictive models.</p>
        </div>  
    </div>
    </div>
</body>
</html>
```

# week-2

##  index.html

```html
<!DOCTYPE html>
<html lang="en">
    <link rel="stylesheet" href="week2.css">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div class ="navbar">
        <a href="#home">Home</a>
        <a href="#about">About</a>
        <div class="dropdown">
            <button class="dropbtn">Register</button>
            <div class="dropdown-content">
                <a href="#Freg">Faculty Register</a>
                <a href="#Sreg">Student Register</a>
            </div>
        </div>
    </div> 
</body>
</html>
```

## main.css

```css
body{
    font-family: cursive;
}
.navbar{
    overflow: hidden;
    background-color: rgb(46, 14, 64);
}
.navbar a{
    float: left;
    font-size: 16px;
    color: white;
    text-align: center;
    padding: 15px 100px;
    text-decoration: none;

}
.dropdown{
    float: left;
    overflow: hidden;

}
.dropdown .dropbtn{
    font-size: 16px;
    border: none;
    outline: none;
    color: white;
    padding: 14px 100px;
    background-color: inherit;
    font-family: inherit;
    margin: 0;
}
.navbar a:hover, .dropdown:hover .dropbtn{
    background-color: rgb(186, 107, 107);
}
.dropdown-content{
    display: none;
    position: absolute;
    background-color: #f9f9f9;
    min-width: 160px;
    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
    z-index: 1;
}
.dropdown-content a{
    float: none;
    color: black;
    padding: 12px 16px;
    text-decoration: none;
    display: block;
    text-align: left;
}
.dropdown-content a:hover{
    background-color: #ddd;
}
.dropdown:hover .dropdown-content{
    display: block;
}

```


# week-3

```html
<!--ng-app tells AngularJS that myApp is the root element of the application -->
<html ng-app="myApp"> 
<head> 
<script src="https://code.angularjs.org/1.4.7/angular.min.js"> 
</script> 
<script src="https://code.angularjs.org/1.4.7/angular-route.min.js"> 
</script> 
<style> 
body { text-align: center; font-family: Arial, Helvetica, sans-serif; } 
h1 { color: green; } 
</style> 
</head> 
<body> 
<h3>Single Page Application in AngularJS</h3> 
<!--hg-template indicates the pages that get loaded as per requirement-->
<script type="text/ng-template" id="first.html"> 
 
<h1>First Page</h1> 
1st page
<h3>{{message}}</h3> 
</script> 
<script type="text/ng-template" id="second.html"> 
<h1>Second Page</h1> <h3>{{message}}</h3> 
</script> 
<script type="text/ng-template" id="third.html"> 
<h1>Third Page</h1> <h3>{{message}}</h3> 
</script> 
<!-- Hyperlinks to load different pages dynamically -->
<a href="#/">First</a> <a href="#/second">Second</a> 
<a href="#/third">Third</a> 
<!--ng-view includes the rendered template of the current route into the main page-->
<div ng-view></div> 
<script> 
var app = angular.module('myApp', []); 
var app = angular.module('myApp', ['ngRoute']); 
app.config(function ($routeProvider) { 
$routeProvider 
.when('/', { templateUrl: 'first.html', controller: 'FirstController' }) 
.when('/second', { templateUrl: 'second.html', controller: 'SecondController' }) 
.when('/third', { templateUrl: 'third.html', controller: 'ThirdController' }) 
.otherwise({ redirectTo: '/' }); 
}); 
// Controller (JS function) maintains application data & behavior using $scope object 
// properties & methods can be attached to the 
// $scope object inside a controller function 
app.controller('FirstController', function ($scope) { 
$scope.message = 'Hello from FirstController ist message'; 
}); 
app.controller('SecondController', function ($scope) { 
$scope.message = 'Hello from SecondController'; 
}); 
app.controller('ThirdController', function ($scope) { 
$scope.message = 'Hello from ThirdController'; 
}); 
</script> 
</body> 
</html>

```

# week-4 

download the img files from following link

https://github.com/ace2884/fullstack/tree/main/week4



## index.html

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>css car</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <link rel='stylesheet' type='text/css' media='screen' href='main.css'>
    <link rel="stylesheet" href="main.css">
    <script src='main.js'></script>
</head>
<body>
    <div class="container">
        <div class="sky">
            <div class="buildings"></div>
                <div class="road"></div>
                <div class="car">
                    <div class="wheel">
                        <img src="car_wheel_left.png" alt=" ">
                    </div>
                    <div class="wheel2">
                        <img src="car_wheel_right.png" alt=" ">
                    </div>
            </div>      
        </div>  
    </div>
</body>
</html>
``` 


## main.css

```css
*{
    margin: 0;
    padding:0;

}
body{
    overflow:hidden;
    animation: shakebody linear 8s infinte;

}
.sky{
    height: 100vh;
    width: 100%;
    background-image: url(background.jpg);
    background-repeat: no-repeat;
    position: absolute;
}
.buildings{
    height: 100vh;
    width: 100%;
    background-image: url(buldings.jpg);
    background-size: cover;
    position: absolute;
    top: -144px;

}
.road{
    height: 60vh;
    width: 800vw;
    background-image: url(road.png);
    background-repeat: repeat-x;
    position: absolute;
    top: 70vh;
    animation: carMove linear 13s infinite;

}
.car{
    height: 100px;
    width: 380px;
    background-image: url(car_body.png);
    background-size: cover;
    background-repeat: no-repeat;
    position:absolute;
    left: 444px;
    bottom: 30vh;
    animation:shake linear .9s infinite;
}
.wheel img{
    width: 77px;
    position:relative;
    top:42px;
    left:42px;
    animation:wheelRotation linear .5s infinite;

}
.wheel2 img{
    width: 77px;
    position:relative;
    top:-39px;
    left:235px;
    animation:wheelRotation linear .87s infinite;
}  

@keyframes wheelRotation{
    100%
    {
        transform: rotate(360deg);

    }
}
@keyframes  carMove
{
 100%{
    transform: translateX(-500vw);
 }
}

@keyframes shake{
    0%
    {
        transform:translate(-5px);
    }
    50%
    {
        transform: translate(5px);
    }
    100%
    {
        transform: translateY(-5px);
    }
}
```


# week-5

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>Page Title</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <link rel='stylesheet' type='text/css' media='screen' href='main.css'>
    <script >
        function validate(){
            var fname = document.reg_form.fname;
            var lname =document.reg_form.lname;
            var gender = document.reg_form.gen;
            var mobile= document.reg_form.mob;
            var email=document.reg_form.email;
            var submit=document.reg_form.submit;
            if (fname.value.length ==0|| lname.value.length==0 ||gender.value.length==0){
                alert("Enter all the fields");
                return false;
            }
            var alpha=/^[A-Za-z]+$/;
            if (!fname.value.match(alpha)||!lname.value.match(alpha)){
                alert("Enter valid first and last name")
                return false;
            }
            if(mobile.value.length != 10){
                alert("Enter 10 digit mobile no");
                return false;
            }
            var validregx= /^[a-zA-Z0-9.!#$%&+/=?^_'{|}~-]+@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/;
            if(email.value.match(validregex)){
                alert("enter valid email id");
                return false;

            }   
            if (submit.value=validate){
                alert("registered sucessfully");
                return true;
            }         
        }
    </script>
</head>
<body>
    <center>
        <form action="" onsubmit="return validate()" name="reg_form">
        <table border="1">
            <thread>
                <th colspan="2"> registration form validation</th>
            </thread>
            <tbody>
                <tr>
                    <td> First name:</td>
                    <td><input type="text" id="fname"></td>

                </tr>
                <tr>
                    <td>last name:</td>
                    <td><input type="text" id="lname">
                    </td>
                </tr>
                <tr>
                    <td>gender :</td>
                    <td>male <input type="radio" id="gen" name="gen">Female <input type="radio" id="gen" name="gen"></td>
                </tr>
                <tr>
                    <td>Mobile no:</td>
                    <td><input type="text" id="mob"></td>

                </tr>
                <tr>
                    <td>email:</td>
                    <td><input type="text" id="email"></td>
                </tr>
                <tr>
                    <td><input type="submit" onclick="confSubmit(this.form);" value="registration"/></td>
                    <td><input type="submit" value="rest"/></td>
                </tr>
            </tbody>
        </table>
        </form>
    </center>
    
</body>
</html>
```

# week-6 

```html
<!DOCTYPE html>
<html>
<head>
    
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>
<body>
    <div class="container">
        <div id="myCarousel" class="carousal slide">
<ol class="carousel-indicators">
    <li class="item1 active">
        <li class="item2">
            <li class="item3">

            </li>
        </li>
    </li>
</ol>   
<div  class="carousel-inner" role="listbox">
    <div class="item active">
        <img src="img1.jpg" alt="image1" width="100%" height="100%">
    </div>
    <div class="item">
        <img src="img2.jpg" alt="image2" width="100%" height="100%">
    </div>
    <div class="item">
        <img src="img3.jpg" alt="image2" width="100%" height="100%">
    </div>
</div>
<a class="left carousel-control" href="#myCarousel" role="button">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">prev</span>
</a>
<a class="right carousel-control" href="#myCarousel" role="button">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">prev</span>
</a>

       </div>
   </div>
   <script>
               $(document).ready(function(){
           $("#myCarousel").carousel();
           $(".item1").click(function(){
               $("#myCarousel").carousel(0);
           })
           $(".item2").click(function(){
               $("#myCarousel").carousel(1); 
       })
       $(".item3").click(function(){
               $("#myCarousel").carousel(2);
       })
       $(".left").click(function(){
       $("#myCarousel").carousel("prev");

       })
       $(".right").click(function(){
       $("#myCarousel").carousel("next");

       })
    });

</script>
</body>
</html>
```

# week-7

#### install express,mongoose,hbs by following commands in Terminal in both week7 and week8


```sh
npm init -y
npm install express
npm install mongoose
npm install hbs
````

##### create a folder templates containing home.html and login.html

## home.hbs

```html
<!DOCTYPE html>
<html>
<head>
 <meta charset='utf-8'>
 <meta http-equiv='X-UA-Compatible' content='IE=edge'>
 <title>Page Title</title>
 <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
 <h1>Welcome to home</h1>
</body>
</html>
```

## login.hbs

```html
<!DOCTYPE html>
<html>
<head>
 <meta charset='utf-8'>
 <meta http-equiv='X-UA-Compatible' content='IE=edge'>
 <title>Page Title</title>
 <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
 <h1>Login</h1>
 <form action="/login" method="post">
 <input type="text" name="name" placeholder="Enter Name">
 <input type="password" name="password" placeholder="Enter Password">
 <input type="submit">
 </form>
</body>
</html>
```

##### create a folder src containing index.js and mongodb.js 


## mongodb.js

```js
const mongoose=require("mongoose")
mongoose.connect("mongodb://localhost:27017/hbs")
.then(()=>{
 console.log("Mongo db connected")
})
.catch(()=>{
 console.log("failed")
})
const LoginSchema=new mongoose.Schema({
 name:{
 type:String,
 required:true
 },
 password:{
 type:String,
 required:true
 }
})
const collection=new mongoose.model("collection1",LoginSchema)
module.exports=collection
```

## index.js

```js
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
```



# week-8


##### create a folder templates containing home.html and login.html

## signup.hbs

```html
<!DOCTYPE html>
<html>
<head>
 <meta charset='utf-8'>
 <meta http-equiv='X-UA-Compatible' content='IE=edge'>
 <title>Page Title</title>
 <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
 <h1>SignUp page</h1>
 <form action="/signup" method="post">
 <input type="text" name="name" placeholder="Enter Name">
 <input type="password" name="password" placeholder="Enter Password">
 <input type="submit">
 </form>
</body>
</html>

```

## home.hbs

```html
<!DOCTYPE html>
<html>
<head>
 <meta charset='utf-8'>
 <meta http-equiv='X-UA-Compatible' content='IE=edge'>
 <title>Page Title</title>
 <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
 <h1>Welcome to home</h1>
</body>
</html>

```

##### create a folder src containing index.js and mongodb.js 


## mongodb.js

```js
const mongoose=require("mongoose")
mongoose.connect("mongodb://localhost:27017/hbs")
.then(()=>{
 console.log("Mongo db connected")
})
.catch(()=>{
 console.log("failed")
})
const LoginSchema=new mongoose.Schema({
 name:{
 type:String,
 required:true
 },
 password:{
 type:String,
 required:true
 }
})
const collection=new mongoose.model("collection1",LoginSchema)
module.exports=collection

```

## index.js

```js
const express=require("express")
const app=express()
const path=require("path")
const hbs=require("hbs")
const collection=require("./mongodb")
const templatePath=path.join(__dirname,'../templates')
app.use(express.json())
app.set("view engine","hbs")
app.set("views",templatePath)
app.use(express.urlencoded({extended:false}))
app.get("/", (req,res)=>{
 res.render("signup")
})
app.post("/signup",async(req,res)=>{
 
 const data={
 name:req.body.name,
 password:req.body.password
 }
 await collection.insertMany([data])
 res.render("home")
}) 
app.listen(3000, ()=>{
 console.log("Port Connected")
}

```

#####  following commands in terminal are used for running the program in browser 

```sh
cd src
node index.js
     # final output in terminal
    -mongodb conncected
```


# week-9


## App.js
```js
const express = require('express');
const bodyparser=require("body-parser")
const bcrypt=require("bcrypt");
const user=require('./models/user');
const mongoose = require('mongoose');
const expressValidator = require("express-validator");
const {check, validationResult} = require('express-validator/check')

const app = express();
const port = process.env.PORT || 80
mongoose.connect("mongodb://localhost:27017/shivafswd",{useNewUrlParser : true, useUnifiedTopology: true});
app.set('view engine', 'pug');

app.use(bodyparser.json());
app.use(bodyparser.urlencoded({extended:true}));



//handling get request

app.get('/',function(req,res){

res.render('index')
})

app.get('/Login',function(req,res){

    res.render('Login')
    })

app.get('/Register',
    function(req,res){
      
    res.render('Register')
    })

//handling post request

app.post('/Register',
[
    check('username').not().isEmpty().isLength({min:5}).withMessage('User name must be 5 characters'),
    check('password').not().isEmpty().isLength({min:6}).withMessage('Password name must be 6 characters'),
    check('age').not().isEmpty().isInt().withMessage('age  must be integer'),
    check('mobile').not().isEmpty().isInt().isLength({min:10}).withMessage('mobile number must be number and 10 characters'),
    check('cpassword').custom((value,{req}) => (value === req.body.password)).withMessage("Confirm password not match with your password"),
    check('email').not().isEmpty().isEmail().normalizeEmail().withMessage("Enetr proper email"),
],

    function(req,res){
        
        const errors= validationResult(req);
        if(!errors.isEmpty())
        {
            return res.status(422).jsonp(errors.array());
        }
        else{

        //console.log(req.body.username)
        const newUser=new user();
        newUser.username=req.body.username;

        
        var salt=bcrypt.genSaltSync(10);
        var hash=bcrypt.hashSync(req.body.password,salt);

        newUser.password=hash;

        newUser.age=req.body.age;
        newUser.mobile=req.body.mobile;

        newUser.save(function(err,result){

            if(err){

                console.log(err);
            }
            else{
                console.log(result);
                res.redirect("Login");
            }
            
        })
    
    }

    })

    app.post('/Login',function(req,res){
        
        user.findOne({"username":req.body.username},function(err,docs){
            if(err)
            {
                console.log(err)
            
            }
            else
            {
                if(docs.username==req.body.username)
                {
                    bcrypt.compare(req.body.password,docs.password,function(err,data)
                    {
                        if(err)
                        {
                            console.log(err);
                        }
                        if(data)
                        {
                            console.log(data);
                            res.send("Welcome");
                        }
                        else
                        {
                            res.send("invalid password");
                        }

                    });
                    

                   
                    
                }
                else
                {
                    //res.send("invalid username or password")
                    res.redirect("Register");
                }

            }

        })
        

        })
    

        app.get('/ajax', function(req, res){
            res.render('ajax', {title: 'An Ajax Search', name: "Search user!"});
        });
        app.post('/ajax', function(req, res){

            user.findOne({username : req.body.name},function(err,docs){
                console.log(req.body.name);
                if(err)
                {
                    console.log(err)
                
                }
                else
                {
                    
                        res.render('ajax', {title: 'An Ajax search', name: "Name "+docs.username+", Age "+docs.age+", Mobile "+docs.mobile });
                   
                }
            });
              
        

           
        });

app.listen(port,() => {console.log(`app is listening on http://localhost:${port}`)})
```

#### create a folder models containing
                - models
                   -user.js

## user.js

```js
const mongoose=require('mongoose');
const Schema=mongoose.Schema;
const userSchema=new Schema(
    {
username : {type:String},
password : {type:String},
age : {type:Number},
mobile : {type:Number}
}
);

module.exports=mongoose.model("user",userSchema);
```

##### create a folder  public containing

               -public
                   -magic.js

## magic.js
```js
$(document).ready(function(){
    $("form#change").on('submit', function(e){
        e.preventDefault();
        var data = $('input[name=name]').val();
        $.ajax({
            type: 'post',
            url: '/ajax',
            data: data,
            dataType: 'text'
        })
        .done(function(data){
            $('h1').html(data.name);
        });
    });
});
```
##### create a folder views containing
          - views
             - ajax.pug
             - index.pug
             - login.pug
             - register.pug
             - my.css
             
## ajax.pug

```pug
doctype html
html(lang="en")
    head
        meta(charset="UTF-8")
        meta(http-equiv="X-UA-Compatible", content="IE=edge")
        meta(name="viewport", content="width=device-width, initial-scale=1.0")
        title Login
        style 
            include ./my.css
        script(src="http://code.jquery.com/jquery-3.1.0.min.js")
        script(src="/magic.js")
        include ./index.pug
    body 
        div(class='container')    
            form(method="post" id="change" align="center" action="/ajax")
                input(type='text', placeholder='search user', name='name')
                input(type="submit", value="Search")
                br
                a(href="") All 
                a(href="") images 
                a(href="") Latest 
                a(href="") News 
                h1 User Details
                p !{name}
```

## index.pug

```pug
doctype html
html(lang="en")
    head
        meta(charset="UTF-8")
        meta(http-equiv="X-UA-Compatible", content="IE=edge")
        meta(name="viewport", content="width=device-width, initial-scale=1.0")
        title index page
        style 
            include ./my.css
    body 
        div(class='header')
            h1 Login and Registration APP 
            a(href="/Login") Login 
            a(href="/Register") Register
            a(href="/ajax") Search User
```
## login.pug

```pug
doctype html
html(lang="en")
    head
        meta(charset="UTF-8")
        meta(http-equiv="X-UA-Compatible", content="IE=edge")
        meta(name="viewport", content="width=device-width, initial-scale=1.0")
        title Login
        style 
            include ./my.css
    body 
        div(class='container')
            include ./index.pug
            h1 Login form
            br
            form(action="/Login" method="post" align="center")
                label(for="username") username
                input(type="text" name="username")
                br
                br
                label(for="password") password
                input(type="password" name="password")
                br
                br
                input(type="submit" name="Login" value="Login")
```
## Register.pug

```pug

doctype html
html(lang="en")
    head
        meta(charset="UTF-8")
        meta(http-equiv="X-UA-Compatible", content="IE=edge")
        meta(name="viewport", content="width=device-width, initial-scale=1.0")
        title Register
        style 
            include ./my.css
    body 
        div(class='container')
            include ./index.pug
            h1 Registration form
            ul(id="errors")
            br
            form(action="/Register" method="post" align="center")
                label(for="username") username
                input(type="text" name="username")
                br
                br
                label(for="password") password
                input(type="password" name="password")
                br
                label(for="cpassword") Confirm password
                input(type="password" name="cpassword")
                br
                br
                label(for="age") user age
                input(type="text" name="age")
                br
                br
                label(for="mobile") user mobile
                input(type="text" name="mobile")
                br
                br
                label(for="email") user email
                input(type="text" name="email")
                br
                br
                input(type="submit" name="Register" value="Register")
                
```

## my css

```css
h1{
    color:blue;
    text-align:center;
}
a:link,a:visited{
    background-color: brown;
    color:white;
    padding:5px 18px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
}
a:hover,a:active{
    background-color: chartreuse;
}
.header {
    padding: 10px;
    text-align: center;
    background: #1abc9c;
    color: white;
    font-size: 30px;
  }
  .container {
    border-radius: 5px;
    background-color: #f2f2f2;
    padding: 10px;
  }

  input{
    width: 20%;
    padding: 12px;
    border: 1px solid #ccc;
    margin-top: 6px;
    margin-bottom: 16px;
    resize: vertical;
  }
  
  input[type=submit] {
    background-color: #04AA6D;
    color: white;
    padding: 12px 20px;
    border: none;
    cursor: pointer;
  }
  
  input[type=submit]:hover {
    background-color: #45a049;
  }
  label{
    color: blue;
    font-size: 22px;
    padding: 8px;
    text-align:left;
  }
```

## Week - 10


![Screenshot (1)](https://github.com/ace2884/fullstack/assets/119153850/4dbe72e9-f729-42b7-aee1-eab078a9f337)



![Screenshot (2)](https://github.com/ace2884/fullstack/assets/119153850/8584d87c-838f-46f4-84da-bd30f36663d8)

