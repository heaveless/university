const FORM = document.getElementById("data-form");

const baseProperties = ["property", "child", "child-properties", "multiple"];
const baseObjects = {
  input: (target) => target.value,
  select2: (target) => target.val(),
  "select2-tags": (target) => target.find(":selected"),
  datepicker: (target) => target.val(),
  "datepicker-multiple": (target) => target.data("daterangepicker"),
};

function getMetadata() {
  const properties = document.querySelectorAll("[property]");

  return Array.from(properties).map((element) => {
    const data = element.getAttributeNames().reduce((acc, curr) => {
      if (baseProperties.includes(curr)) acc[curr] = element.getAttribute(curr);
      return acc;
    }, {});
    return { ...data, element };
  });
}

function getExecutables(metadata) {
  return metadata.map((meta) => {
    if (_.has(meta, "multiple")) {
      const chilElements = meta.element.childNodes;

      const hasChild = _.has(meta, "child");
      const hasChildProperties = _.has(meta, "child-properties");

      Array.from(chilElements).map((child) => {
        if (hasChild && hasChildProperties) {
          const libs = meta.element.getAttribute("child").split(",");
          const props = meta.element
            .getAttribute("child-properties")
            .split(",");

          const mapped = libs.map((lib, idx) => ({
            exec: baseObjects[lib],
            target: child,
            prop: props[idx],
          }));
        }
      });

      if (_.has(meta, "child") && _.has(meta, "child-properties")) {
        const libs = meta.element.getAttribute("child").split(",");
        const props = meta.element.getAttribute("child-properties").split(",");

        const objs = libs.map((lib, idx) => ({
          exec: baseObjects[lib],
          target: chilElements[idx],
          prop: props[idx],
        }));

        meta.exec = () =>
          objs.reduce(
            (acc, curr) => (
              acc.push({ [curr.prop]: curr.exec(curr.target) }), acc
            ),
            []
          );
      } else if (_.has(meta, "child")) {
        const lib = meta.element.getAttribute("child");

        // const obj = { exec: baseObjects[lib],
        //         target:
        //     prop: meta.property };
      } else {
        meta.exec = () => {
          if (meta.element.hasAttribute("select2-tags"))
            return baseObjects["select2-tags"](meta.element);

          return [];
        };
      }
    } else {
      meta.exec = () => "baseObjects[meta.property]";
    }
    return _.pick(meta, ["property", "exec"]);
  });
}

function generatePayload() {
  const metadata = getMetadata();
  const executables = getExecutables(metadata);
  console.log(executables);
  const payload = executables.reduce(
    (acc, curr) => ((acc[curr.property] = curr.exec()), acc),
    {}
  );
  console.log(payload);
  return {};
}

function submit() {
  FORM.onsubmit = () => {
    try {
      const payload = generatePayload();

      return false;
    } catch (error) {
      return false;
    }
  };
}

function bootstrap() {
  submit();
}

bootstrap();
