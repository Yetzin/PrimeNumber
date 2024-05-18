const { parentPort } = require('node:worker_threads');

parentPort.on('message', ({latest, numeros}) => {
    let div = false, k = 0;
    while(k < numeros.length) {
        div = latest % numeros[k] == 0;
        if(div || numeros[k]*numeros[k] > latest) {
            k = 0;
            break;
        }
        k++;
    }

    parentPort.postMessage({
        success: !div,
        n: latest,
    });
});
