class Map {
  constructor() {
    this.items = {};
  }
  has(key) {
    return this.items.hasOwnProperty(key);
  }
  set(key, value) {
    this.items[key] = value;
  }
  get(key) {
    return this.items[key];
  }
  delete(key) {
    if (this.has(key)) {
      delete this.items[key];
      return true;
    }
    return false;
  }
  clear() {
    this.items = {};
  }
  size() {
    return Object.keys(this.items).length;
  }
  keys() {
    return Object.keys(this.items);
  }
  values() {
    return Object.values(this.items);
  }
  getItems() {
    return this.items;
  }
}

export default Map;
