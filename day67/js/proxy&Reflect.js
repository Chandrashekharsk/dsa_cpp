const p1 = {
  fname: "john",
  lname : "Doe",
};

const p1Proxy = new Proxy(p1, {
  get(target, prop){
    if(prop in target) return target[prop];
    return false;
  },
  set(target, prop, val){
    if(!(prop in target)) throw new Error(`${prop} doesn't exists there`);
    else{
      switch(prop){
        case 'fname':
        case 'lname':
          if(typeof val !== 'string'){
            throw new Error(`${prop} must be a string`);
            break;
          }
        
        case age:
          if(typeof val !== 'number'){
            throw new Error(`${prop} must be a number`);
            break;
          }
          if(val<=0){
            throw new Eroor(`${prop} must be a a positive`);
          }
        default:
          target[prop] = val;
      }
    }
  },
})