/**
 * Created by zhangsha on 16-7-29.
 */
'use strict';
const repl = require('repl');
const init = require('./action/InitAction');
const tobarcode = require('./action/TransformBarcodeSelectAction');
const toPostcodSelect = require('./action/TransformPostCodeSelectAction');
const barcodeTopostcode = require('./action/TransformPostCodeAction');
const postcodeTobarcode = require('./action/TransformBarcodeAction');
const router = require('./action/Router');
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
