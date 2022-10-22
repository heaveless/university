const datasource = document.getElementById("datasource");
const datasourceContent = datasource.innerHTML;
const dataFmt = datasourceContent.replace(/&#39;/g, '"');
const dataObject = JSON.parse(dataFmt);

function loadLibs() {
  $("[select2]").select2();

  $("[select2-tags]").select2({
    tags: true,
  });

  $("[datepicker]").daterangepicker({
    singleDatePicker: true,
    showDropdowns: true,
  });

  $("[datepicker-multiple]").daterangepicker();
}

function deleteItem(container) {
  container.remove();
}

function createItem(node, items = [], className = "-") {
  const container = node.parentNode.parentNode.querySelector(":scope > * + *");

  const wrapper = document.createElement("div");
  wrapper.classList.add("form__input-item", className);

  items.forEach((item, idx) => {
    const { type, tag, value } = dataObject.properties[item];
    const element = document.createElement(tag);

    element.type = type;
    element.setAttribute("field", item);
    element.setAttribute(item, value);
    element.classList.add("form-control");

    // FIX ME
    if (item == "select2") {
      const property = container.getAttribute("property");
      const options = dataObject.data[property][idx];
      options.forEach((opt) => {
        const option = document.createElement("option");
        option.textContent = opt;

        element.appendChild(option);
      });
    }
    // END FIX

    wrapper.appendChild(element);
    loadLibs();
  });

  const button = document.createElement("button");
  const properties = {
    type: "button",
    textContent: "-",
    onclick: () => deleteItem(wrapper),
  };

  _.assign(button, properties);
  button.classList.add("btn", "btn-sm", "btn-danger");

  wrapper.appendChild(button);

  container.appendChild(wrapper);
}
