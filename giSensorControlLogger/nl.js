var dateFormat = require('dateformat');
var serialport = require("serialport");
var SerialPort = serialport.SerialPort; // localize object constructor
var sensorNode = "40BEDDF7";

var sp = new SerialPort("COM4", {
  parser: serialport.parsers.readline("\n")
});

sp.on('open', function(){
  console.log('Serial Port Opend');
  sp.on('data', function(data){
//      console.log(data[0]);
//      console.log(+data);
//      sys.puts(+data);

      var now = new Date();
      var day=dateFormat(now.request_date, "yyyy-mm-dd h:MM:ss");

      console.log("%s, %s, %s", sensorNode, day, data);
  });
// close port?
});

//console.log(
//    ts_hms.getFullYear() + '-' + 
//    (ts_hms.getMonth() + 1).slice(-2) + '-' + 
//    ("0" + (ts_hms.getDate() + 1)).slice(-2) + ' ' +
//    (ts_hms.getHours()).slice(-2) + ':' +
//    (ts_hms.getMinutes()).slice(-2) + ':' +
//    (ts_hms.getSeconds()).slice(-2));
