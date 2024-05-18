const { parentPort } = require('node:worker_threads');

function method(i) {
    const start = new Date();
    let numeros = [ 2 ], latest = 3;
    while(i > numeros.length) {
		let div = false, k = 0;
        while(k < numeros.length) {
			div = latest % numeros[k] == 0;
			if(div) {
				latest++;
				k = 0;
                break;
			}
            k++;
		}
		if(!div) {
			numeros.push(latest);
            latest++;
		}
	}
    const end = new Date();

    return (`1) El número primo en la posición ${i} es: ${numeros[i-1]}\n${(end.getTime() - start.getTime())} ms`);
}

parentPort.on('message', (i) => {
    const response = method(i);
    parentPort.postMessage(response);
});
