// How to implement Generic Tree in JavaScript:

// 1. get parent node.
// 2. get children nodes.
// 3. get all the descendants.
// 4. remove all the descendants.
// 5. remove children nodes.


// Created Unique ID
const uniqueId = (() => {
  function* uniqueIdGenerator() {
    let id = Date.now();
    
    while(true) {
      yield id++;
    }
  }
  
  const gen = uniqueIdGenerator();
  
  return () => gen.next().value;
})()


//Created Tree
class Tree {
  #children = new Map();
  #parent = null;
  #id = uniqueId();
  #name;
  
  constructor(name) {
    if(!name || typeof name !== 'string' || !name.trim().length) {
      throw new Error('Name must be a non-empty String');
    }
    
    this.#name = name;
  }

  
  //Using Setter and Getter
  get name() {
    return this.#name;
  }
  
  set name(newName) {
    if(!newName || typeof newName !== 'string' || !newName.trim().length) {
      throw new Error('Cannot change name.Name must be a non-empty String');
    }
    
    this.#name = newName;
  }

  get identifier() {
    return this.#id;
  }

  //Creating child Node
  get children() {
    return Array.from(this.#children.values());
  }

  //Creating Parent Node
  get parentNode() {
    return this.#parent;
  }

  set parentNode(newParent) {
    if(newParent !== this.parentNode && (newParent === null || newParent instanceof Tree)) {
      if(this.#parent) {
         this.#parent.removeChildNode(this);
      }
      
      this.#parent = newParent;
      
      if(newParent) {
        newParent.appendChildNode(this);
      }
    }
  }

  get childrenCount() {
    return this.#children.size;
  }

  createChildNode(name) {
    const newNode = new Tree(name);
    this.#children.set(newNode.identifier, newNode);
    newNode.parentNode = this;
    
    return newNode;
  }

  hasChildNode(needle) {
    if(needle instanceof Tree) {
      return this.#children.has(needle.identifier);
    }
    
    for(let child of this.children) {
      if(child.name === needle || this.identifier === needle) {
        return true
      }
    }
    
    return false;
  }

  getChildNode(nameOrId) {
    for(let child of this.children) {
      if(child.name === nameOrId || this.identifier === nameOrId) {
        return child;
      }
    }
    
    return null;
  }

  appendChildNode(node) {
    if(!(node instanceof Tree) || this.hasChildNode(node)) return;
    
    if(node === this) throw new Error('Node cannot contain itself');
    
    let parent = this.parentNode;
    while(parent !== null) {
      if(parent === node) throw new Error('Node cannot contain one of its ancestors');
      parent = parent.parentNode;
    }
    
    this.#children.set(node.identifier, node);
    node.parentNode = this;
  }

  
  // Removing child Node
  removeChildNode(needle) {
    if(!this.hasChildNode(needle)) return;
    
    let removedNode;// Removing all the descendants.
    
    if(needle instanceof Tree) {
      this.#children.delete(needle.identifier);
      removedNode = needle;
    } else {
      for(let child of this.children) {
        if(child.name === needle || child.identifier === needle) {
          this.#children.delete(child.identifier);
          removedNode = child;
          break;
        }
      }
    }
    
    if(removedNode) {
      removedNode.parentNode = null;
    }
  }

  appendChildNode(node) {
    if(!(node instanceof Tree) || this.hasChildNode(node)) return;
    
    if(node === this) throw new Error('Node cannot contain itself');
    
    let parent = this.parentNode;
    while(parent !== null) {
      if(parent === node) throw new Error('Node cannot contain one of its ancestors');
      parent = parent.parentNode;
    }
    
    this.#children.set(node.identifier, node);
    node.parentNode = this;
  }

  #getTreeString = (node, spaceCount = 0) => {
    let str = "\n";
  
    node.children.forEach((child) => {
      str += `${" ".repeat(spaceCount)}${child.name}${this.#getTreeString(child, spaceCount + 2)}`
    })

    return str;
  }

  print() {
    console.log(`\n${this.name}${this.#getTreeString(this, 2)}`);
  }

  traverse(cb) {
    for(let child of this.children) {
      if(cb(child) === true || child.traverse(cb) === true) {
        return true;
      }
    }
  }

  findNodeByName(name) {
    let foundNode = null;
    
    this.traverse(node => {
      if(node.name === name) {
        foundNode = node;
        return true;
      }
    })
    
    return foundNode;
  }

  findAllNodesByName(name) {
    const children = [];
    
    this.traverse(node => {
      if(node.name === name ) {
        children.push(node);
      }
    })
    
    return children;
  }
}
