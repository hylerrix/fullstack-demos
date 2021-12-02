/**
 * Created by zhangsha on 16-8-1.
 */

class Router {
    constructor(actions) {
        this.currentAction = 'init';
        this.actions = actions;
    }

    switchRouter(cmd) {
        let router = this.actions.find(action => action.name === this.currentAction);
        let result = router.doAction(cmd);
        let nextRouter = this.actions.find(action => action.name === result);

        this.currentAction = nextRouter.name;
    }

    start() {
        console.log(this.actions.find(item => item.name === this.currentAction).help);
    }
}

module.exports = Router;

