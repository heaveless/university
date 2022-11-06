const datasource = document.getElementById("datasource");
const datasourceContent = datasource.innerHTML;
const dataFmt = datasourceContent.replace(/&#34;/g, '"');
const dataObject = JSON.parse(dataFmt);

const baseElements = {
  languages: (value) =>
    `<div class="item"><div class="item__title">${value}</div></div>`,
  programming_languages: (value) =>
    ` <div class="item"><div class="item__title">${value}</div></div>`,
  aptitudes: (value) => `<li class="list__item">${value}</li>`,
  skills: (value) => `<li class="list__item">${value}</li>`,
};

const baseFormats = {
  languages: (obj) => `${obj.language}: ${obj.level}`,
  programming_languages: (obj) => obj,
  aptitudes: (obj) => obj,
  skills: (obj) => obj[""],
};

function loadProperties() {
  const [storage] = dataObject.value;
  const context = JSON.parse(storage);
  console.log(context);
  const elements = document.querySelectorAll("[property]");
  const properties = Array.from(elements).map((element) => ({
    element,
    property: element.getAttribute("property"),
    multiple: element.hasAttribute("multiple"),
  }));

  properties.forEach(({ element, property, multiple }) => {
    if (!multiple) element.textContent = context[property];
    else {
      const baseElement = baseElements[property];
      const baseFormat = baseFormats[property];

      const list = context[property];
      list.forEach((item) => {
        if (baseElement && baseFormat) {
          const value = baseFormat(item);
          const currentElement = baseElement(value);

          element.insertAdjacentHTML("beforeend", currentElement);
        }
      });
    }
  });
}

function bootstrap() {
  loadProperties();
}

bootstrap();
