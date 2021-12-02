import { BlitzApiHandler, getSession } from "blitz"

// http://localhost:3001/api/hello?a=1&b=2
const handler: BlitzApiHandler = async (req, res) => {
  const session = await getSession(req, res)

  res.statusCode = 200
  res.setHeader("Content-Type", "application/json")

  const result = {
    name: "hylerrix",
    sessionUserId: session.userId,
    reqCookies: req.reqCookies,
    reqQuery: req.query,
    reqBody: req.body,
  }

  if (req.method === "POST") {
    res.end(JSON.stringify({ type: 'POST', ...result }))
  } else {
    res.end(JSON.stringify({ type: 'NOT POST', ...result }))
  }
}

export default handler
