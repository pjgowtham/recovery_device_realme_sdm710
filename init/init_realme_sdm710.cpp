/*
   Copyright (c) 2015, The Linux Foundation. All rights reserved.
   Copyright (C) 2016 The CyanogenMod Project.
   Copyright (C) 2019-2020 The LineageOS Project.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "log.h"
#include <string>
#include <fstream>

using namespace std;
using android::base::GetProperty;
using std::string;

namespace android {
namespace init {

void load_RMX1921() {
      property_set("ro.product.device", "RMX1921");
      property_set("ro.product.product.device", "RMX1921");
      property_set ("ro.build.product", "RMX1921");
      property_set ("ro.product.name", "RMX1921");
      property_set ("ro.product.model", "RMX1921");      
      property_set ("ro.product.product.model", "RMX1921");
      property_set("ro.separate.soft", "19651");
      property_set("ro.vendor.product.device.oem", "RMX1921"); 
}

void load_RMX1921EU() {
      property_set("ro.product.device", "RMX1921EU");
      property_set("ro.product.product.device", "RMX1921EU");      
      property_set("ro.build.product", "RMX1921EU");
      property_set("ro.product.name", "RMX1921EU");
      property_set("ro.product.model", "RMX1921");
      property_set("ro.product.product.model", "RMX1921");
      property_set("ro.separate.soft", "19651");
      property_set("ro.vendor.product.device.oem", "RMX1921");        
}

void load_RMX1901() {
      property_set("ro.product.device", "RMX1901");
      property_set("ro.product.product.device", "RMX1901");
      property_set("ro.build.product", "RMX1901");
      property_set("ro.product.name", "RMX1901");      
      property_set("ro.product.model", "RMX1901");
      property_set("ro.product.product.model", "RMX1901");
      property_set("ro.separate.soft", "19605");
      property_set("ro.vendor.product.device.oem", "RMX1901");
  
}

void load_RMX1901CN() {
      property_set("ro.product.device", "RMX1901CN");
      property_set("ro.product.product.device", "RMX1901CN");
      property_set("ro.build.product", "RMX1901CN");
      property_set("ro.product.name", "RMX1901CN");      
      property_set("ro.product.model", "RMX1901");
      property_set("ro.product.product.model", "RMX1901");
      property_set("ro.separate.soft", "19601");
      property_set("ro.vendor.product.device.oem", "RMX1901");

}
void load_RMX1851() {
      property_set("ro.product.device", "RMX1851");
      property_set("ro.product.product.device", "RMX1851");
      property_set("ro.build.product", "RMX1851");
      property_set("ro.product.name", "RMX1851");       
      property_set("ro.product.model", "RMX1851");
      property_set("ro.product.product.model", "RMX1851");
}

void load_RMX1971() {
      property_set("ro.product.device", "RMX1971");
      property_set("ro.product.product.device", "RMX1971");
      property_set("ro.build.product", "RMX1971");
      property_set("ro.product.name", "RMX1971");      
      property_set("ro.product.model", "RMX1971");
      property_set("ro.product.product.model", "RMX1971");
}

void load_RMX1971CN() {
      property_set("ro.product.device", "RMX1971CN");
      property_set("ro.product.product.device", "RMX1971CN");
      property_set("ro.build.product", "RMX1971CN");
      property_set("ro.product.name", "RMX1971CN");
      property_set("ro.product.model", "RMX1971");
      property_set("ro.product.product.model", "RMX1971");
}

void init_RMX1921() {
	string oppo_sku = android::base::GetProperty("ro.boot.product.hardware.sku", "");

               if (oppo_sku == "nfc_ese" || oppo_sku == "RMX1921EU") {	
			load_RMX1921EU();
               } else {
			load_RMX1921();
                            }
}
                            
void init_RMX1901() {
    const char* path = "/proc/partitions";
	std::ifstream infile(path);
	string line;
	while (std::getline(infile, line))
	{
		if (line.find("sda11") != string::npos)
		{
			if (line.substr(17, 7) == "5091328") {
				load_RMX1901CN();
                break;
			}
			else
			{
				load_RMX1901();
                break;
			}
		}
	}
}

void init_RMX1971() {
    const char* path = "/proc/partitions";
	std::ifstream infile(path);
	string line;
	while (std::getline(infile, line))
	{
		if (line.find("sda11") != string::npos)
		{
			if (line.substr(17, 7) == "4337664") {
				load_RMX1971CN();
                break;
			}
			else
			{
				load_RMX1971();
                break;
			}
		}
	}
}
		
void vendor_load_properties() {
	      
	std::ifstream infile("/proc/oppoVersion/prjName");
        string prjName;	
	getline(infile, prjName);
	
	if (prjName == "19651") {
              init_RMX1921();
                       }          
     
	if (prjName == "18041") {
	      init_RMX1901();
	}

	if (prjName == "18621") {
	      load_RMX1851();
                }

	if (prjName == "19691") {
	      init_RMX1971();
	}
}
}  // namespace init
}  // namespace android
