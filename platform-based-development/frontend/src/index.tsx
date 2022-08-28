import { render, h } from 'preact'

import App from './bootstrap'

render(<App />, document.querySelector('#root') as Element)
