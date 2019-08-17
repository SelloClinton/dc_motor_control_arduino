function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "untitled:6"};
	this.sidHashMap["untitled:6"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/External Interrupt"] = {sid: "untitled:1"};
	this.sidHashMap["untitled:1"] = {rtwname: "<Root>/External Interrupt"};
	this.rtwnameHashMap["<Root>/Function-Call Subsystem"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<Root>/Function-Call Subsystem"};
	this.rtwnameHashMap["<S1>/function"] = {sid: "untitled:4"};
	this.sidHashMap["untitled:4"] = {rtwname: "<S1>/function"};
	this.rtwnameHashMap["<S1>/Digital Output"] = {sid: "untitled:6"};
	this.sidHashMap["untitled:6"] = {rtwname: "<S1>/Digital Output"};
	this.rtwnameHashMap["<S1>/Pulse Generator"] = {sid: "untitled:13"};
	this.sidHashMap["untitled:13"] = {rtwname: "<S1>/Pulse Generator"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "untitled:6:7"};
	this.sidHashMap["untitled:6:7"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Data Type Conversion"] = {sid: "untitled:6:11"};
	this.sidHashMap["untitled:6:11"] = {rtwname: "<S2>/Data Type Conversion"};
	this.rtwnameHashMap["<S2>/Digital Output"] = {sid: "untitled:6:12"};
	this.sidHashMap["untitled:6:12"] = {rtwname: "<S2>/Digital Output"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();