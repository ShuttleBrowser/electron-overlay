const overlay = require('./build/Release/overlay.node')

console.log(overlay.create("dsdsdsdsd", 51551))
console.log(overlay.remove(50))

module.exports = overlay