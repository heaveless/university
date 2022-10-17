const events = ["blur", "change", "keypress"];

function onResult(node, response) {
  if (response) {
    node.classList.add("success");
    node.classList.remove("error");
  } else {
    node.classList.add("error");
    node.classList.remove("success");
  }
}

function isNotEmpty(node) {
  const exec = () => onResult(node, /^[a-zA-Z\s]+$/.test(node.value));
  events.forEach((evt) => node.addEventListener(evt, exec));
}

function isEmail(node) {
  const exec = () =>
    onResult(
      node,
      /(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/.test(
        node.value
      )
    );
  events.forEach((evt) => node.addEventListener(evt, exec));
}

function isPhone(node) {
  const exec = () =>
    onResult(
      node,
      /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/.test(node.value)
    );
  events.forEach((evt) => node.addEventListener(evt, exec));
}

const validators = {
  isNotEmpty: (node) => isNotEmpty(node),
  isEmail: (node) => isEmail(node),
  isPhone: (node) => isPhone(node),
};

function loadValidators() {
  const inputs = Array.from(document.querySelectorAll("[field]"));
  const isSuccess = inputs.every((input) => {
    const validateAttribute = input.getAttribute("validate");
    if (validateAttribute) {
      const validatorTypes = validateAttribute.split("|");
      validatorTypes.forEach((validator) => validators[validator](input));

      return true;
    }

    return true;
  });
  console.log(isSuccess);
  return false;
}
