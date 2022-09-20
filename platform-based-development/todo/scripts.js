// Global

const EMPTY = "";

const FORM = document.querySelector("form");
const CONTAINER = document.getElementById("container");

const storage = {
  todoList: [],
};

// Utils

function uuidv4() {
  return ([1e7] + -1e3 + -4e3 + -8e3 + -1e11).replace(/[018]/g, (c) =>
    (
      c ^
      (crypto.getRandomValues(new Uint8Array(1))[0] & (15 >> (c / 4)))
    ).toString(16)
  );
}

// Main
function submit(event) {
  event.preventDefault();

  let newItem = null;

  const formData = new FormData(FORM);
  for (const [k, v] of formData.entries()) {
    newItem = { id: uuidv4(), [k]: v };
  }

  addItem(newItem);
  render();
  clear();
}

function render() {
  CONTAINER.innerHTML = EMPTY;

  storage.todoList.forEach((e, idx) => addElement(e, ++idx));
}

function clear() {
  const INPUT = FORM.querySelector("input");
  INPUT.value = EMPTY;
}

function addItem(item) {
  if (!item.todo || !item.todo.trim()) return;

  storage.todoList.push(item);
}

function addElement({ id, todo }, idx) {
  const ITEM_CONTAINER = document.createElement("div");
  const ITEM_INPUT = document.createElement("input");
  const ITEM_SPAN = document.createElement("span");
  const ITEM_P = document.createElement("p");
  const ITEM_BUTTON = document.createElement("button");

  ITEM_CONTAINER.id = id;
  ITEM_CONTAINER.classList.add("todo__item");

  ITEM_INPUT.type = "checkbox";
  ITEM_INPUT.addEventListener("change", function () {
    if (!this.checked) {
      ITEM_P.classList.remove("line-through");
    } else {
      ITEM_P.classList.add("line-through");
    }
  });

  ITEM_SPAN.textContent = idx;

  ITEM_P.textContent = todo;

  ITEM_BUTTON.textContent = "x";
  ITEM_BUTTON.addEventListener("click", function () {
    const parentElement = this.parentNode;
    const id = parentElement.id;

    removeItem(id);
    render();
  });

  ITEM_CONTAINER.appendChild(ITEM_SPAN);
  ITEM_CONTAINER.appendChild(ITEM_INPUT);
  ITEM_CONTAINER.appendChild(ITEM_P);
  ITEM_CONTAINER.appendChild(ITEM_BUTTON);

  CONTAINER.appendChild(ITEM_CONTAINER);
}

function removeItem(id) {
  const idx = storage.todoList.findIndex((e) => e.id == id);
  storage.todoList.splice(idx, 1);
}

function removeElement(id) {
  const ITEM_CONTAINER = document.getElementById(id);
  ITEM_CONTAINER.remove();
}

function bootstrap() {
  FORM.addEventListener("submit", submit);
}

bootstrap();
