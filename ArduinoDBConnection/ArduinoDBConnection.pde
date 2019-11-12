import de.bezier.data.sql.*;
import processing.serial.*;

MySQL mysql;
String[] a;
int end = 10;
String serial;
String serial2;
Serial port;
Serial port2;

void setup(){
 String user = "root";
 String pass = "Qaz1234%";
 String database = "";
 
 mysql = new MySQL( this, "localhost", database, user, pass );

 port = new Serial(this, "COM7", 9600);
 port.clear();
 
 port2 = new Serial(this, "COM5", 9600);
 port2.clear();
 
 serial = port.readStringUntil(end);
 serial = null;
 
 serial2 = port2.readStringUntil(end);
 serial2 = null;
}

void draw(){
 
  while(port.available() > 0){
  serial = port.readStringUntil(end); 
 }
 
 if(serial != null){
   a = split(serial, ",");
   println(a[0]);
   println(a[1]);
   println(a[2]);
   println(a[3]);
   println(a[4]);
   
   
   
 }
 if(serial2 != null){
    a[5] = serial2; 
    println(a[5]);
 }
 function();
}
void function(){
   if(mysql.connect()){
    mysql.query("insert into data(MQ2_LPG, MQ2_SMOKE, MQ2_CO, Acc X, Acc Y, Temp)values (" + a[0] + "," + a[1] + "," + a[2] + "," + a[3] + "," + a[4] + "," + a[5] + ")"); 
   }
   else{
     
   }
   mysql.close();
 }
