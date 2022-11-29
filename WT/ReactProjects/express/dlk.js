var express=require('express');
var app=express();
app.use(function(req,res,next){
    console.log("start")
    next();
})
app.get("/",function(req,res,next){
    res.send("middle");
    next();
})
app.use("/",function(req,res)
    {
        console.log("end")
    })
app.listen(3000)
