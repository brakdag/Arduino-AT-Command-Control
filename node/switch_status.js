/* This program emulates read digital input
made by Gustavo David Ferreyra  brakdag@gmail.com
MIT license

This program read te pin 03 for PULL_UP of arduino and print
this data in the console out. 
*/
SerialPort = require('serialport');
var port = new SerialPort('COM3', {
  parser: SerialPort.parsers.readline('\n')
});
var bandera = 0;
port.on('data', function (data) {
  console.log('Data: ' + data);
  if ( bandera == 0) setInterval(leer,1000);
  bandera = 1;
});

function leer(){
	port.write('ATDIP+3\r\n');
}
