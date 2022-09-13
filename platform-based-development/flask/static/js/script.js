const URL = "http://here.com/send";

const serializeObject = (form) => {
  const data = {};

  Array.from(form.elements).forEach((field) => {
    if (!field.name || ["submit"].indexOf(field.type) > -1) return;

    data[field.name] = field.value;
  });

  return data;
};

const send = (payload, cb) => {
  axios
    .post(URL, payload)
    .then((res) => cb(res.data, null))
    .catch((err) => cb(null, err.message));
};

const showResponse = (data, err) => {
  const errorText = document.getElementById("error-message");

  if (!err) errorText.innerText = JSON.stringify(data);
  else errorText.innerText = err;
};

const boot = () => {
  const form = document.getElementById("data-form");

  form.addEventListener("submit", (evt) => {
    evt.preventDefault();

    const payload = serializeObject(form);
    send(payload, showResponse);
  });
};

boot();
