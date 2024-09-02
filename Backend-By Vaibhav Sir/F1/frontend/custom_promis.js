
function customePromiseExectuor(){
    console.log('Custom Promise Executor Function');
}

function customePromiseExectuor(resolve,reject){
    setTimeout(() => {
        console.log('Custom Promise Executor Function');
        resolve('Resolved Value');
    }, 10000);
}


function customPromise(executorFunctionArg){
    executorFunctionArg(
        (responseArg) => {
            this.state = 'fulfilled';
            console.log('Inside Resolve Function',responseArg);
        }
        ,
        (errorArg) => {
            this.state = 'rejected';
            console.log('Inside Reject Function',errorArg);
        }
    )
    this.state = 'pending';
    let returnVal = undefined;
}

var responseErrorValue
var promise1 = new customPromise(customePromiseExectuor);
