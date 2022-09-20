
alert("bbb")
// Storage

const storage = {
  todoList:[]
};

// Utils

function uuidv4() {
  return ([1e7]+-1e3+-4e3+-8e3+-1e11).replace(/[018]/g, c =>
    (c ^ crypto.getRandomValues(new Uint8Array(1))[0] & 15 >> c / 4).toString(16)
  );
}

// Main
function submit(event) {
  event.preventDefault()

  const formData = new FormData(document.querySelector('form'))
  for (const k, v of formData.entries()) {
    const newItem = { id: uuidv4(), [k]: v};
    addItem(newItem);
    addElement(newItem);
  }
}

function addItem(item) {
  storage.todoList.push(item);
}

function addElement({ id, item }) {
  const ITEM_CONTAINER = document.createElement("div");
  const ITEM_INPUT = document.createElement("input");
  const ITEM_P = document.createElement("p");
  const ITEM_BUTTON = document.createElement("button");

  ITEM_CONTAINER.id = id;

  ITEM_P.innerHTML = item;

  ITEM_BUTTON.innerHTML = "x";
  ITEM_BUTTON.addEventListener("click", function (){
    const parentElement = this.parentNode;
    const id = parentElement.id;

    removeItem(id);
    removeElement(id);
  })

  ITEM_CONTAINER.appendChildren(ITEM_INPUT);
  ITEM_CONTAINER.appendChildren(ITEM_P);
  ITEM_CONTAINER.appendChildren(ITEM_BUTTON);
}

function removeItem(id) {

}

function removeElement(id) {

}

function bootstrap() {
  const form = document.querySelector("form");
  form.addEventListener("submit", submit);
}

bootstrap();

