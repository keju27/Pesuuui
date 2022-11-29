var MongoClient=require("mongodb").MongoClient
var url="mongodb://localhost:27017/class"
MongoClient.connect(url,function(err,db)
{
    if(err) throw err;
    {
        var dbo=db.db("classe")
        dbo.createCollection("employee",function(err,res))
        console.log("collection created");
        db.close()
    }
});