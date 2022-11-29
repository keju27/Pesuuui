const url = require('url')
const querystring = require('querystring')
const http = require('http')
const {MongoClient}=require('mongodb')
var Dburl="mongodb://localhost:27017/"
var Client = new MongoClient(Dburl);
http.createServer(function(req,res){
res.writeHead(200, {'Content-Type': 'text/html'});
var dish = req.url.toString().substring(1);
console.log(dish);
var toPrint={};
Client.connect(function(err,db){
    if (err)
    {
    console.log(err);
    }
    var dbo = db.db("Bangalore_City");
    dbo.collection("restaurants").find({}).toArray(function(err, result) {
    if (err){
    console.log(err);
    }
    //console.log(result);
    for(var i=0;i<result.length;i++)
    {
    if(result[i].best_dish ==dish)
    {
    console.log(result[i]);
    console.log("Your restaurant is " + result[i].rest_name +" it's location is " + result[i].rest_addr + "Available online"+result[i].available_for_online_booking)
    
    }
    }
    db.close();
    });
    });
    res.end();
    }).listen(8080);