const { Worker } = require('node:worker_threads');

const args = process.argv.slice(2);

// const worker_1 = new Worker("./workers/method_1.js");
// const worker_2 = new Worker("./workers/method_2.js");
const worker_3 = new Worker("./workers/method_3.js");

const [ i ] = args;

// worker_1.postMessage(i);
// worker_2.postMessage(i);
worker_3.postMessage(i);

// worker_1.on('message', (msg) => {
//     console.log("\n"+msg);
//     worker_1.terminate();
// })

// worker_2.on('message', (msg) => {
//     console.log("\n"+msg);
//     worker_2.terminate();
// })

worker_3.on('message', (msg) => {
    console.log("\n"+msg);
    worker_3.terminate();
});
