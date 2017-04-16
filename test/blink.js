/* this program emulates classic blink app
made by Gustavo David Ferreyra 
MIT license
*/

var SerialPort = require('serialport');

var port = new SerialPort('COM3'); // in linux use SerialPort('/dev/ttyACMO');
 
var status = 'apagado';


function split(){
	if (status == 'apagado') 
	{
		port.write('ATDOH+13\r\n');
		status = 'encendido';
	}
	else if (status == 'encendido')
	{
		port.write('ATDOL+13\r\n');
		status = 'apagado';
	}
}

setInterval(split,1000);