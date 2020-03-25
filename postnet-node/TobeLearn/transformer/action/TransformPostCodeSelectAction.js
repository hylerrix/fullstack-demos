/**
 * Created by zhangsha on 16-7-29.
 */
const createAction = require('./CreateAction');

let name = '条码转邮编';
let help = `
1-输入条码
2-返回上一层
q-退出`.trim();

class TransformPostCodeSelectView extends createAction {
    constructor(name, help) {
        super(name, help)
    }

    doAction(cmd) {
        switch (cmd) {
            case '1':
                return '输入条码';
            case '2':
                return 'init';
            case 'q':
                process.exit(0);
                return;
            default:
                console.log("无效的输入");
                return 'init';
        }
    }
}

module.exports = new TransformPostCodeSelectView(name, help);
