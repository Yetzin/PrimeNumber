const { Worker } = require('node:worker_threads');

const start = new Date();
const [ i ] = process.argv.slice(2);

let numeros = [ 2, 3 ], latest = 5;

function getPosition(i) {
    if (i > numeros.length) {
        const last_n = numeros[numeros.length - 1];
        const limit = last_n*last_n;

        let h = (limit - latest) / 2;
        let found = [];

        while (latest < limit) {
            const worker = new Worker("./workers/method_4.js");

            worker.postMessage({
                latest: latest,
                numeros: numeros,
            })

            worker.on('message', ({ success, n }) => {
                if (success) {
                    found.push(n);
                }
                h--;
                if (h == 0) {
                    if (found.length > 0) {
                        numeros = [
                            ...numeros,
                            ...found.sort((a, b) => a - b)
                        ];
                    }
                    getPosition(i);
                }
                worker.terminate();
            })

            latest+=2;
        }
    } else {
        end();
    }
}

function end() {
    const end = new Date();

    console.log(`4) El número primo en la posición ${i} es: ${numeros[i-1]}\n${(end.getTime() - start.getTime())} ms`);
}

getPosition(i);
