// Promise is an object cretead using Promise() constructor. It has two properties:
//     - state: initially pending, then changes to fulfilled or rejected. 
//     - value: undefined, return value or error

function promiseExecutor() {
    setTimeout(() => {
        console.log('INSIDE PROMISE EXECUTOR');
        
    }, 10000);
}

var promise1 = new Promise(promiseExecutor);

let responseErrorValue;
var promise2 = new Promise((promiseExecutor);
promise1.catch(someValue) => {
    responseErrorValue = someValue;
});
