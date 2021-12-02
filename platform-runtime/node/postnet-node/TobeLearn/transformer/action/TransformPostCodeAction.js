/**
 * Created by zhangsha on 16-7-29.
 */
const createAction = require('./CreateAction');
const sendRequest = require('../../request');

let name = '输入条码';
let help = '请输入合法的条码';
let router = 'barcodetopostcode';

class TransformPostcodeAction extends createAction {
    constructor(name, help) {
        super(name, help);
    }

    doAction(cmd) {
        sendRequest(router, cmd);
        return '条码转邮编';
    }
}

module.exports = new TransformPostcodeAction(name, help);