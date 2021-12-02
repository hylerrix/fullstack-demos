/**
 * Created by zhangsha on 16-7-29.
 */
'use strict'

const createAction = require('./CreateAction');
const sendRequest = require('../../request');

const request = require('sync-request');
let name = '输入邮编';
let help = '请输入合法的邮编';
let router = 'postcodetobarcode';

class TransformBarcodeAction extends createAction {

    constructor(name, help) {
        super(name, help);
    }
    doAction(cmd) {
        sendRequest(router, cmd);
        return '邮编转条码';
    }
}


module.exports = new TransformBarcodeAction(name, help);
