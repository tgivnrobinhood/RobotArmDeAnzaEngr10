var http = require('http');
var fs = require('fs');
var index = fs.readFileSync( 'index.html');

var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});

//1101 for Leo Song's macbook
//14301 for Leo Song's pc


var port = new SerialPort('/dev/cu.usbmodem14301',{ 
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});


port.open(function (err) {
    if (err) {
      return console.log('Error opening port: ', err.message)
    }})

port.pipe(parser);



var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(index);
});

var io = require('socket.io').listen(app);

io.on('connection', function(socket) {
    
    socket.on('dataIn',function(data){
        
        console.log( data);
        
        port.write( data.status );
    
    });77
    
});

app.listen(3000);
