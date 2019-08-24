function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled:4"};
	this.sidHashMap["untitled:4"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Digital Input"] = {sid: "untitled:4"};
	this.sidHashMap["untitled:4"] = {rtwname: "<Root>/Digital Input"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "untitled:6"};
	this.sidHashMap["untitled:6"] = {rtwname: "<Root>/To Workspace"};
	this.rtwnameHashMap["<S1>/Digital Input"] = {sid: "untitled:4:4"};
	this.sidHashMap["untitled:4:4"] = {rtwname: "<S1>/Digital Input"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "untitled:4:3"};
	this.sidHashMap["untitled:4:3"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
