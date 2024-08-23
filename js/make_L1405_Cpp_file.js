const fs=require('fs');

const json=JSON.parse(fs.readFileSync('./js/L1405_width_param_KN.js'));
console.log(json);

makeParamCodes(json, 'width_KN_');
makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_param_KN.js')),
	       'pole_KN_');

makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_param_Kmp.js')),
	       'pole_Kmp_');
makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_width_param_Kmp.js')),
	       'width_Kmp_');

makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_param_KzeroN.js')),
	       'pole_KzeroN_');
makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_width_param_KzeroN.js')),
	       'width_KzeroN_');

function makeParamCodes(obj, header){
    let code='';
    code += doubleArray(obj, 'Range', header+'range')+'\n';
    code += doubleArray(obj, 'chi2',  header+'chi2')+'\n';
    code += doubleArray(obj, 'NDF',   header+'NDF')+'\n';
    code += doubleArray(obj, 'Mean',  header+'mean')+'\n';
    code += doubleArray(obj, 'Lower', header+'lower')+'\n';
    code += doubleArray(obj, 'Upper', header+'upper')+'\n';
    console.log(code);
}

function doubleArray(obj, iName, pName){
    let str='double '+pName+'[]={ ';
//    json.forEach(a=> console.log(a.Range));
    obj.forEach(a=> str+=a[iName]+', ');
    str=str.slice(0, -2)+' };';
//    console.log(str);
    return str;
}
