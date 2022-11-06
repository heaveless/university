const FORM = document.getElementById("data-form");

const baseProperties = ["property", "child", "multiple"];
const baseObjects = {
  input: (target) => target.value,
  textarea: (target) => target.value,
  select2: (target) => $(target).val(),
  "select2-tags": (target) =>
    $(target)
      .select2("data")
      .map((e) => e.text),
  datepicker: (target) => $(target).val(),
  "datepicker-multiple": (target) => {
    const { startDate, endDate } = $(target).data("daterangepicker");
    const format = "MM/DD/YYYY";

    return {
      startDate: startDate.format(format),
      endDate: endDate.format(format),
    };
  },
};

function getMetadata() {
  const properties = document.querySelectorAll("[property]");

  return Array.from(properties).map((element) => {
    const data = element.getAttributeNames().reduce((acc, curr) => {
      if (baseProperties.includes(curr)) acc[curr] = element.getAttribute(curr);
      return acc;
    }, {});
    return _.assign(data, { element });
  });
}

function getExecutables(metadata) {
  return metadata.map((meta) => {
    if (_.has(meta, "multiple")) {
      const hasChild = _.has(meta, "child");

      meta.exec = () => {
        if (hasChild && meta.element.getAttributeNames()) {
          const props = meta.element.getAttribute("child").split(",");

          const childrenElements = Array.from(
            meta.element.querySelectorAll(":scope > *")
          );

          return childrenElements.map((child) => {
            const grandChildrens = Array.from(
              child.querySelectorAll("[field]")
            );

            return grandChildrens.reduce((acc, curr, idx) => {
              const lib = curr.getAttribute("field");

              const mapped = {
                exec: baseObjects[lib],
                target: curr,
                property: props[idx],
              };

              return (acc[mapped.property] = mapped.exec(mapped.target)), acc;
            }, {});
          });
        } else if (hasChild) {
          const childrenElements = Array.from(
            meta.element.querySelectorAll(":scope > *")
          );

          return childrenElements.map((child) => {
            const grandChildren = child.querySelector("[field]");
            const lib = grandChildren.getAttribute("field");

            const mapped = {
              exec: baseObjects[lib],
              target: grandChildren,
            };

            return mapped.exec(mapped.target);
          });
        } else {
          const children = meta.element;
          const lib = children.getAttribute("field");
          const mapped = {
            exec: baseObjects[lib],
            target: children,
          };
          return mapped.exec(mapped.target);
        }
      };
    } else {
      const attribute = meta.element.getAttribute("field");

      const mapped = {
        exec: baseObjects[attribute],
        target: meta.element,
      };

      meta.exec = () => mapped.exec(mapped.target);
    }

    return _.pick(meta, ["property", "exec"]);
  });
}

function getPayload() {
  const metadata = getMetadata();
  const executables = getExecutables(metadata);

  return executables.reduce(
    (acc, curr) => ((acc[curr.property] = curr.exec()), acc),
    {}
  );
}

function validate(payload) {
  return [true, payload];
}

function submit() {
  FORM.onsubmit = () => {
    try {
      const payload = getPayload();
      const [isSuccess, data] = validate(payload);
      // console.log(isSuccess, data);

      axios.post("/send", data).then((res) => {
        const { success, key } = res.data;
        console.log(key)
        if (success) window.location.href = `/curriculum/${key}`;
      });

      return false;
    } catch (error) {
      return false;
    }
  };
}

function bootstrap() {
  loadValidators();
  submit();
}

bootstrap();
