var MongoClient = require("mongodb").MongoClient;
var url = require("url");
var http=require("http");
var qs=require("querystring");
const parse = require("path");

http.createServer(function(request,response){
    if (request.method =="GET") {
        var myurl=url.parse(request.url);
        var query=myurl.query;
        var qobj =qs.parse(query);
        var url1="mongodb://localhost:27017";
        MongoClient.connect(url1,function(err,client){
            if(err) throw err;
            const db=client.db("Bangalore_City");
            db.collection("restaurants")
            .find(qobj, {projection:{ _id:0,rest_id:1 ,rest_name:7}})
            .sort({res_id: 1})
            .toArray(function(err,result){
                if (err) throw err;

                console.log(result);
                //response.write(result);
                client.close();
            });
        });
    }}).listen(8081)
    console.log("works");