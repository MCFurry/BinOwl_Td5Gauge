/*
 * This file is part of the Td5Gauge Firmware (https://github.com/k0sci3j/Td5Gauge).
 * Copyright (c) 2022 Michal Kosciowski BinOwl.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * 	WEB.cpp
 *  Created on: 7.04.2022
 *  Author: BinOwl
 *
 */

#include "WEB.h"

const char* MAIN_page =
"<!DOCTYPE html>"
"<html>"
"<style>"
"body {"
"  margin: 0;"
"  min-height: 100vh;"
"  display: flex;"
"  flex-direction: column;"
"  justify-content: center;"
"  align-items: center;"
"  background-color: #000;"
"  overflow-y: auto;"
"}"
".container {"
"  display: flex;"
"  flex-direction: column;"
"  align-items: center;"
"  width: 100%;"
"  flex-grow: 1;"
"}"
".box {"
"  border-radius: 10px;"
"  font-weight: bold;"
"  padding: 50px;"
"  box-sizing: border-box;"
"  color: #FFF;"
"  margin: 30px;"
"  box-shadow: 0px 2px 18px -4px;"
"  text-align: center;"
"  width: 100%;"
"}"
".f {"
"  background-color: #024d27;"
"  color: #FF0;"
"}"
"#V, #LV, #BV, #AOV {"
"  font-size: 96px;"
"}"
"#U, #LU, #BU, #AON {"
"  font-size: 56px;"
"}"
"#N, #BN, #LN {"
"  font-size: 36px;"
"}"
".button-container {"
"  text-align: center;"
"  margin-top: 20px;"
"}"
".button {"
"  font-size: 24px;"
"  padding: 10px 20px;"
"  margin: 5px;"
"  cursor: pointer;"
"  background-color: #555;"
"  color: #fff;"
"  border: none;"
"  border-radius: 5px;"
"}"
".button:hover {"
"  background-color: #777;"
"}"
"</style>"
"<body>"
"  <div class=\"container\">"
"    <div class=\"box f\">"
"      <span id=\"N\">?</span><br>"
"      <span id=\"V\">?</span>&nbsp;<span id=\"U\">?</span><br>"
"    </div>"
"    <div class=\"box f\">"
"        <span id=\"AON\">?</span><br>"
"        <span id=\"AOV\">?</span><br>"
"        <button class=\"button\" onclick=\"toggleAutoOff()\">toggle</button>"
"      </div>"
"      <div class=\"box f\">"
"        <span id=\"BN\">?</span><br>"
"        <span id=\"BV\">?</span><br>"
"        <div class=\"button-container\">"
"          <button class=\"button\" onclick=\"decreaseBrightnessValue()\">-</button>"
"          <button class=\"button\" onclick=\"increaseBrightnessValue()\">+</button>"
"        </div>"
"      </div>"
"    <div class=\"box f\">"
"      <span id=\"LN\">?</span><br>"
"      <span id=\"LV\">?</span>&nbsp;<span id=\"LU\">?</span><br>"
"      <div class=\"button-container\">"
"        <button class=\"button\" onclick=\"decreaseTemplimValue()\">-</button>"
"        <button class=\"button\" onclick=\"increaseTemplimValue()\">+</button>"
"      </div>"
"    </div>"
"  </div>"
"  <script>"
"    reqData();"
"    setInterval(reqData, 200);"
"    function reqData() {"
"      var xhr = new XMLHttpRequest();"
"      xhr.onload = function() {"
"        if (this.status == 200) {"
"          var data = JSON.parse(xhr.responseText);"
"          document.getElementById('N').innerHTML = data.n;"
"          document.getElementById('V').innerHTML = data.v;"
"          document.getElementById('U').innerHTML = data.u;"
"        } else {"
"          document.getElementById('N').innerHTML = \"?\";"
"          document.getElementById('V').innerHTML =  \"?\";"
"          document.getElementById('U').innerHTML = \"?\";"
"        }"
"      };"
"      xhr.open('GET', 'readVal', true);"
"      xhr.send();"
"    }"
"    reqBrightness();"
"    setInterval(reqBrightness, 200);"
"    function reqBrightness() {"
"      var xhr = new XMLHttpRequest();"
"      xhr.onload = function() {"
"        if (this.status == 200) {"
"          var data = JSON.parse(xhr.responseText);"
"          document.getElementById('BN').innerHTML = data.n;"
"          document.getElementById('BV').innerHTML = data.v;"
"          document.getElementById('BU').innerHTML = data.u;"
"        } else {"
"          document.getElementById('BN').innerHTML = \"?\";"
"          document.getElementById('BV').innerHTML = \"?\";"
"          document.getElementById('BU').innerHTML = \"?\";"
"        }"
"      };"
"      xhr.open('GET', 'readBrightness', true);"
"      xhr.send();"
"    }"
"    reqAutoOff();"
"    setInterval(reqAutoOff, 200);"
"    function reqAutoOff() {"
"      var xhr = new XMLHttpRequest();"
"      xhr.onload = function() {"
"        if (this.status == 200) {"
"          var data = JSON.parse(xhr.responseText);"
"          document.getElementById('AON').innerHTML = data.n;"
"          document.getElementById('AOV').innerHTML = data.v;"
"        } else {"
"          document.getElementById('AON').innerHTML = \"?\";"
"          document.getElementById('AOV').innerHTML = \"?\";"
"        }"
"      };"
"      xhr.open('GET', 'readAutoOff', true);"
"      xhr.send();"
"    }"
"    reqLim();"
"    setInterval(reqLim, 200);"
"    function reqLim() {"
"      var xhr = new XMLHttpRequest();"
"      xhr.onload = function() {"
"        if (this.status == 200) {"
"          var data = JSON.parse(xhr.responseText);"
"          document.getElementById('LN').innerHTML = data.n;"
"          document.getElementById('LV').innerHTML = data.v;"
"          document.getElementById('LU').innerHTML = data.u;"
"        } else {"
"          document.getElementById('LN').innerHTML = \"?\";"
"          document.getElementById('LV').innerHTML = \"?\";"
"          document.getElementById('LU').innerHTML = \"?\";"
"        }"
"      };"
"      xhr.open('GET', 'readLim', true);"
"      xhr.send();"
"    }"
"    function increaseBrightnessValue() {"
"      console.log(\"Increase brightness value\");"
"      var xhr = new XMLHttpRequest();"
"      xhr.open('GET', 'writeBrightnessPlus', true);"
"      xhr.send();"
"    }"
"    function decreaseBrightnessValue() {"
"      console.log(\"Decrease brightness value\");"
"      var xhr = new XMLHttpRequest();"
"      xhr.open('GET', 'writeBrightnessMin', true);"
"      xhr.send();"
"    }"
"    function increaseTemplimValue() {"
"      console.log(\"Increase temperature limit value\");"
"      var xhr = new XMLHttpRequest();"
"      xhr.open('GET', 'writeTemplimPlus', true);"
"      xhr.send();"
"    }"
"    function decreaseTemplimValue() {"
"      console.log(\"Decrease temperature limit value\");"
"      var xhr = new XMLHttpRequest();"
"      xhr.open('GET', 'writeTemplimMin', true);"
"      xhr.send();"
"    }"
"    function toggleAutoOff() {"
"      console.log(\"Toggle auto-off\");"
"      var xhr = new XMLHttpRequest();"
"      xhr.open('GET', 'writeAutoOffToggle', true);"
"      xhr.send();"
"    }"
"  </script>"
"</body>"
"</html>";

const char* UPDATE_page =
"<!DOCTYPE html>"
     "<html lang='en'>"
     "<head>"
         "<meta charset='utf-8'>"
         "<meta name='viewport' content='width=device-width,initial-scale=1'/>"
     "</head>"
     "<body>"
	 "<h1 style=\"color:red\">CONNECT POWER SUPPLY AND DO NOT TURN OFF IGNITION KEY FROM POSITION 2</h1>"
     "<form method='POST' action='' enctype='multipart/form-data'>"
         "Firmware:<br>"
         "<input type='file' accept='.bin' name='firmware'>"
         "<input type='submit' value='Update Firmware'>"
     "</form>"
     "</body>"
     "</html>";

const char* UPDATE_success =
"<META http-equiv=\"refresh\" content=\"15;URL=/\">Update Success! Rebooting...";

WebServer server(80);
HTTPUpdateServer httpUpdater;

String ajaxValue = "";
String limitValue = "";
String autoOffValue = "";
String brightnessValue = "";

void RunWebServer() {
    WiFi.softAP(NAME);
	MDNS.begin(NAME);
	server.begin();
	MDNS.addService("http", "tcp", 80);
	server.on("/", HTTP_GET, []() {
		server.sendHeader("Connection", "close");
    	server.send(200, "text/html", MAIN_page);
  	});
  // Read values from code
	server.on("/readVal", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
		server.send(200, "application/json", ajaxValue);
	});
  server.on("/readLim", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
		server.send(200, "application/json", limitValue);
	});
  server.on("/readAutoOff", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
		server.send(200, "application/json", autoOffValue);
	});
  server.on("/readBrightness", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
		server.send(200, "application/json", brightnessValue);
	});
  // Control brightness
  server.on("/writeBrightnessPlus", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
    web_update_lcd_backlight(+5);
	});
  server.on("/writeBrightnessMin", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
    web_update_lcd_backlight(-5);
	});
  // Control temperature limit
  server.on("/writeTemplimPlus", HTTP_GET, [](){
    web_update_temp_alarm(+1);
		server.sendHeader("Connection", "close");
	});
  server.on("/writeTemplimMin", HTTP_GET, [](){
    web_update_temp_alarm(-1);
		server.sendHeader("Connection", "close");
	});
  // Control Auto OFF
  server.on("/writeAutoOffToggle", HTTP_GET, [](){
		server.sendHeader("Connection", "close");
    web_update_auto_off();
	});
	httpUpdater.setup(&server);
}
