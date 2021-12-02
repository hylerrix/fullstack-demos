/**
 * Created by zhangsha on 16-8-2.
 */
'use strict';

const repl = require('repl');
const init = require('./transformer/action/InitAction');
const tobarcode = require('./transformer/action/TransformBarcodeSelectAction');
const toPostcodSelect = require('./transformer/action/TransformPostCodeSelectAction');
const barcodeTopostcode = require('./transformer/action/TransformPostCodeAction');
const postcodeTobarcode = require('./transformer/action/TransformBarcodeAction');
const router = require('./transformer/action/Router');

const actions = [
    init,
    toPostcodSelect,
    barcodeTopostcode,
    tobarcode,
    postcodeTobarcode
];

let routerObj = new router(actions);
routerObj.start();

function handleCmd(cmd, context, filename, done) {
    routerObj.switchRouter(cmd.trim());
    routerObj.start();
    done(null);
}

var replServer = repl.start({prompt: "> ", eval: handleCmd});

