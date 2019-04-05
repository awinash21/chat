const fs = require('fs');
const file = fs.createWriteStream('./big.file');

for(let i=0; i<= 10000; i++) {
  file.write(i+'Sending hello from server side.\n');
}

file.end();
