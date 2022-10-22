const events=["blur","change","keypress"];function onResult(node,response){if(response){node.classList.add("success");node.classList.remove("error");}else{node.classList.add("error");node.classList.remove("success");}}
function isNotEmpty(node){const exec=()=>onResult(node,/^[a-zA-Z\s]+$/.test(node.value));events.forEach((evt)=>node.addEventListener(evt,exec));}
function isEmail(node){const exec=()=>onResult(node,/(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/.test(node.value));events.forEach((evt)=>node.addEventListener(evt,exec));}
function isPhone(node){const exec=()=>onResult(node,/^[\+]?[(]?[0-9]{3}[)]?[-\s\.]?[0-9]{3}[-\s\.]?[0-9]{4,6}$/im.test(node.value));events.forEach((evt)=>node.addEventListener(evt,exec));}
const validators={isNotEmpty:(node)=>isNotEmpty(node),isEmail:(node)=>isEmail(node),isPhone:(node)=>isPhone(node),};function loadValidators(){const inputs=Array.from(document.querySelectorAll("[field]"));const isSuccess=inputs.every((input)=>{const validateAttribute=input.getAttribute("validate");if(validateAttribute){const validatorTypes=validateAttribute.split("|");validatorTypes.forEach((validator)=>validators[validator](input));return true;}
return true;});console.log(isSuccess);return false;}
const datasource=document.getElementById("datasource");const datasourceContent=datasource.innerHTML;const dataFmt=datasourceContent.replace(/&#39;/g,'"');const dataObject=JSON.parse(dataFmt);function loadLibs(){$("[select2]").select2();$("[select2-tags]").select2({tags:true,});$("[datepicker]").daterangepicker({singleDatePicker:true,showDropdowns:true,});$("[datepicker-multiple]").daterangepicker();}
function deleteItem(container){container.remove();}
function createItem(node,items=[],className="-"){const container=node.parentNode.parentNode.querySelector(":scope > * + *");const wrapper=document.createElement("div");wrapper.classList.add("form__input-item",className);items.forEach((item,idx)=>{const{type,tag,value}=dataObject.properties[item];const element=document.createElement(tag);element.type=type;element.setAttribute("field",item);element.setAttribute(item,value);element.classList.add("form-control");if(item=="select2"){const property=container.getAttribute("property");const options=dataObject.data[property][idx];options.forEach((opt)=>{const option=document.createElement("option");option.textContent=opt;element.appendChild(option);});}
wrapper.appendChild(element);});const button=document.createElement("button");const properties={type:"button",textContent:"-",onclick:()=>deleteItem(wrapper),};_.assign(button,properties);button.classList.add("btn","btn-sm","btn-danger");wrapper.appendChild(button);container.appendChild(wrapper);loadLibs();}
const FORM=document.getElementById("data-form");const baseProperties=["property","child","multiple"];const baseObjects={input:(target)=>target.value,textarea:(target)=>target.value,select2:(target)=>$(target).val(),"select2-tags":(target)=>$(target).select2("data").map((e)=>e.text),datepicker:(target)=>$(target).val(),"datepicker-multiple":(target)=>{const{startDate,endDate}=$(target).data("daterangepicker");const format="MM/DD/YYYY";return{startDate:startDate.format(format),endDate:endDate.format(format),};},};function getMetadata(){const properties=document.querySelectorAll("[property]");return Array.from(properties).map((element)=>{const data=element.getAttributeNames().reduce((acc,curr)=>{if(baseProperties.includes(curr))acc[curr]=element.getAttribute(curr);return acc;},{});return _.assign(data,{element});});}
function getExecutables(metadata){return metadata.map((meta)=>{if(_.has(meta,"multiple")){const hasChild=_.has(meta,"child");meta.exec=()=>{if(hasChild&&meta.element.getAttributeNames()){const props=meta.element.getAttribute("child").split(",");const childrenElements=Array.from(meta.element.querySelectorAll(":scope > *"));return childrenElements.map((child)=>{const grandChildrens=Array.from(child.querySelectorAll("[field]"));return grandChildrens.reduce((acc,curr,idx)=>{const lib=curr.getAttribute("field");const mapped={exec:baseObjects[lib],target:curr,property:props[idx],};return(acc[mapped.property]=mapped.exec(mapped.target)),acc;},{});});}else if(hasChild){const childrenElements=Array.from(meta.element.querySelectorAll(":scope > *"));return childrenElements.map((child)=>{const grandChildren=child.querySelector("[field]");const lib=grandChildren.getAttribute("field");const mapped={exec:baseObjects[lib],target:grandChildren,};return mapped.exec(mapped.target);});}else{const children=meta.element;const lib=children.getAttribute("field");const mapped={exec:baseObjects[lib],target:children,};return mapped.exec(mapped.target);}};}else{const attribute=meta.element.getAttribute("field");const mapped={exec:baseObjects[attribute],target:meta.element,};meta.exec=()=>mapped.exec(mapped.target);}
return _.pick(meta,["property","exec"]);});}
function getPayload(){const metadata=getMetadata();const executables=getExecutables(metadata);return executables.reduce((acc,curr)=>((acc[curr.property]=curr.exec()),acc),{});}
function validate(payload){return[true,payload];}
function submit(){FORM.onsubmit=()=>{try{const payload=getPayload();const[isSuccess,data]=validate(payload);axios.post("/send",data).then((res)=>{const{success,key}=res.data;console.log(key)
if(success)window.location.href=`/curriculum/${key}`;});return false;}catch(error){return false;}};}
function bootstrap(){loadValidators();submit();}
bootstrap();