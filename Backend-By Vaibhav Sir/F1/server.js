var express = require("express");
var app = express();

app.use("/",express.static("./frontend"));

app.listen(8080);


// localhost IP  127.0.0.1 (default)