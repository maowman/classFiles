const fetch = require("node-fetch");
let workers = [];
const url = "http://apc.aca.ntu.edu.tw/fcc/ShowContent.aspx?pid=90";
let counter = 0;
const work = async () => {
    await fetch(url);
    return;
}

const main = async () =>{
    while (true){
        counter +=1;
        for (let i=0; i<10 ; i++){
            workers.push(work());
        }
        await Promise.all(...workers);
        console.log(counter);
        workers = [];
    }
    return 0;
}
main()
