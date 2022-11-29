var {MongoClient} = require('mongodb');
var url = "mongodb://localhost:27017/";
var client = new MongoClient(url)
client.connect(function(err, db) {
if (err){
console.log(err);
}
var dbo = db.db("Bangalore_City");
var my_rest_details = [{
rest_name:"MTR",
rest_id:"1",
rest_addr: "LALBAGH ROAD. #14, Lalbagh Road, Bengaluru - 560027 ",
available_for_online_booking:"yes",
ratings:"4.7",
best_dish:"BisiBeleBath",
grade : "A"
},
{
rest_name:"CTR",
rest_id:"2",
rest_addr: "7th Cross Rd, Malleswaram, Bengaluru, Karnataka 560003",
available_for_online_booking:"yes",
ratings:"4.9",
best_dish:"MasalaDosa",
grade : "A"
},
{
rest_name:"VIDHYARTHI-BAVAN",
rest_id:"3",
rest_addr: "LALBAGH ROAD. #14, Lalbagh Road, Bengaluru - 560027 ",
available_for_online_booking:"yes",
ratings:"4.9",
best_dish:"BenneMasalaDosa",
grade : "A"
},
{
rest_name:"1947 , Jayanagar",
rest_id:"4",
rest_addr: "5th phase, 282, 15th Cross Rd, KR Layout, JP Nagar Phase 6,J. P. Nagar, Bengaluru, Karnataka 560078"
,available_for_online_booking:"No",
ratings:"4.4",
best_dish:"NorthThali",
grade : "A2"
},
{
rest_name:"New Krishna Bhavan",
rest_id:"5",
rest_addr: "Opposite Sampige theater, Sampige Road, 33/39, S End Rd,Bengaluru, Karnataka 560020",available_for_online_booking:"yes",
ratings:"4.5",
best_dish:"BadamHalwa",
grade : "A"
},
{
rest_name:"Bombat Bhojana",
rest_id:"6",
rest_addr: "17, Gandhi Bazaar Main Rd, Gandhi Bazaar, Basavanagudi,Bengaluru, Karnataka 560004",available_for_online_booking:"No",
ratings:"4.5",
best_dish:"SouthIndianUnlimitedplate",
grade : "A2"
},
{
rest_name:"Rajdhani ,Orion Mall",
rest_id:"7",
rest_addr: "No.26/1, Level 2, Orion Mall, Brigade Gateway, Dr RajkumarRd, Malleswaram, Bengaluru, Karnataka 560055",available_for_online_booking:"No",
ratings:"4.9",
best_dish:"RajastaniUnlimitedplate",
grade : "A"
},
{
rest_name:"Kakal Kai Ruchi",
rest_id:"9",
rest_addr: "1&8, Kothnur Main Rd, opp. Big bazaar, Nataraja Layout, RBILayout, JP Nagar 7th Phase, Bengaluru, Karnataka 560078",available_for_online_booking:"yes",
ratings:"4.7",
best_dish:"Roti ki tokri",
grade : "A2"
}];
dbo.collection("restaurants").insertMany(my_rest_details,function(err,res){
if(err)
{
console.log(err);
}
console.log(`Number of items inserted is, ${res.insertedCount}`);
db.close();
});
});


