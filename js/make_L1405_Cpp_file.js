const fs=require('fs');

// makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_width_Kmp.js')), 'width_Kmp_');
// makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_width_KN.js')), 'width_KN_');
// makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_width_KzeroN.js')), 'width_KzeroN_');

// makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_Kmp.js')), 'pole_Kmp_');
makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_KN.js')), 'pole_KN_');
// makeParamCodes(JSON.parse(fs.readFileSync('./js/L1405_pole_KzeroN.js')), 'pole_KzeroN_');

function makeParamCodes(obj, header){
//    console.log(obj, header);
    let code='';
    code += doubleArray(obj, 'cutHeight', header+'cut_hight')+'\n';
    code += doubleArray(obj, 'chi2',  header+'chi2')+'\n';
    code += doubleArray(obj, 'NDF',   header+'NDF')+'\n';
    code += doubleArray(obj, 'mean',  header+'mean')+'\n';
    code += doubleArray(obj, 'lower', header+'lower')+'\n';
    code += doubleArray(obj, 'upper', header+'upper')+'\n';
    code += doubleArray(obj, 'fitLower', header+'fit_lower')+'\n';
    code += doubleArray(obj, 'fitUpper', header+'fit_upper')+'\n';
    console.log(code);
}

function doubleArray(obj, iName, pName){
    let str='const double '+pName+'[]={ ';
//    json.forEach(a=> console.log(a.Range));
    obj.forEach(a=> str+=a[iName]+', ');
    str=str.slice(0, -2)+' };';
//    console.log(str);
    return str;
}
