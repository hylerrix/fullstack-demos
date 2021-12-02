/**
 * Created by zhangsha on 16-7-29.
 */
const createAction = require('./CreateAction');


let name = 'init';
let help = `
welcome 
1-条码转邮编
2-邮编转条码
q-退出`.trim();



class Init extends createAction{
    constructor(name, help){
        super(name, help);
    }

    doAction(cmd){
        switch(cmd) {
            case '1':
                return '条码转邮编';
            case '2':
                return '邮编转条码';
            case 'q':
                process.exit(0);
                return;
            default:
                console.log("无效的输入");
                return 'init';
        }
    }

}

module.exports = new Init(name, help);
